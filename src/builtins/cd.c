/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:36:09 by babkar            #+#    #+#             */
/*   Updated: 2022/09/25 14:33:24 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtins.h"

int	check_path(char *path)
{
	struct stat	sb;

	if (stat(path, &sb) == -1)
		return (puterr("No such file or directory", 1));
	if (S_ISREG (sb.st_mode))
		return (puterr("cd: not a directory", 1));
	return (0);
}

int	access_path(char *arg)
{
	char	cwd[1024];
	char	*path;

	if (!ft_strcmp(".", arg))
	{
		path = getcwd(cwd, sizeof(cwd));
		if (!path)
			return (puterr("No such file or directory", 0));
		chdir(path);
	}
	else if (!ft_strcmp("-", arg))
	{
		if (!ft_getenv("OLDPWD"))
			return (puterr("xsh: cd: OLDPWD not set", 1));
		chdir(ft_getenv("OLDPWD"));
	}
	else
	{
		if (check_path(arg))
			return (1);
		chdir(arg);
	}
	return (0);
}

void	update_oldpwd(void)
{
	t_var	var;
	char	*path;

	if (does_env_variable_exist("OLDPWD"))
	{
		path = ft_getenv("PWD");
		fill_env_variable("OLDPWD", path);
	}
	else
	{
		var.name = "OLDPWD";
		var.value = ft_getenv("PWD");
		if (var.value == NULL)
			var.value = " ";
		ft_envadd_back(&g_global.environment, ft_envnew(var));
	}
}

void	update_env(t_var var)
{
	char	cwd[1024];
	char	*path;

	update_oldpwd();
	if (does_env_variable_exist("PWD"))
	{
		path = getcwd(cwd, sizeof(cwd));
		fill_env_variable("PWD", path);
	}
	else
	{
		path = getcwd(cwd, sizeof(cwd));
		var.name = "PWD";
		var.value = strdup(path);
		ft_envadd_back(&g_global.environment, ft_envnew(var));
	}
}

int	cd(t_smpcmd smpcmd)
{
	t_var	var;
	char	*arg;

	var.name = NULL;
	var.value = NULL;
	var.flag = 0;
	var.next = NULL;
	if (!smpcmd.args)
	{
		if (!ft_getenv("HOME"))
			return (puterr("xsh: cd: HOME not set", 1));
		chdir(ft_getenv("HOME"));
		update_env(var);
		return (2);
	}
	arg = smpcmd.args->token;
	if (access_path(arg))
		return (1);
	update_env(var);
	g_global.status = 0;
	return (2);
}
