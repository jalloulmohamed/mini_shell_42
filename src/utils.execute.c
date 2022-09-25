/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:04:29 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/25 15:45:00 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*command_path(t_smpcmd smpcmd)
{
	int			j;
	char		*cmd_path;
	struct stat	sb;
	char		**paths;

	paths = xsh_path();
	if (!paths)
		return (NULL);
	j = 0;
	cmd_path = NULL;
	while (paths[j] != NULL)
	{
		if (stat(ft_strunite(paths[j], smpcmd.command), &sb) != -1)
		{
			cmd_path = ft_strunite(paths[j], smpcmd.command);
			break ;
		}
		j++;
	}
	return (cmd_path);
}

char	**xsh_env_2d(void)
{
	char	**env;
	t_env	*env_idx;
	int		i;
	char	*string;

	i = 0;
	env_idx = g_global.environment;
	env = (char **)malloc((ft_envsize(env_idx) + 1) * sizeof(char *));
	add_to_garbage(env);
	if (!env)
		return (NULL);
	while (env_idx)
	{
	string = ft_strjoin(env_idx->name, "=");
	string = ft_strjoin(string, env_idx->value);
	env[i] = string;
	env_idx = env_idx->next;
	i++;
	}
	env[i] = NULL;
	return (env);
}

void	run_command(t_smpcmd smpcmd, char **args, char *line)
{
	char	*cmd_path;
	int		p;

	g_global.running = 1;
	g_global.heredoc = 0;
	rl_catch_signals = 1;
	p = fork();
	if (p == 0)
	{
		cmd_path = command_path(smpcmd);
		if (cmd_path)
			execve(cmd_path, args, xsh_env_2d());
		else
			ft_putstr_fd(ft_strjoin("minishell: command not found: ", line), 2);
		exit(127);
	}
	waitpid(p, &g_global.exit_status, 0);
	g_global.running = 0;
	rl_catch_signals = 0;
	exit_status();
}

void	ex_excve(char *line, t_smpcmd smpcmd, char **args)
{
	int		p;
	char	*string;

	string = "minishell: No such file or directory: ";
	if (line[0] == '.' && line[1] == '/')
	{
		g_global.running = 3;
		p = fork();
		if (p == 0)
		{
			execve(line, args, xsh_env_2d());
			ft_putstr_fd(ft_strjoin(string, line), 2);
			exit(127);
		}
		waitpid(p, &g_global.exit_status, 0);
		exit_status();
	}
	else
		run_command(smpcmd, args, line);
}
