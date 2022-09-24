/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:26:19 by babkar            #+#    #+#             */
/*   Updated: 2022/09/24 16:08:14 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtins.h"

void	print_export(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->name)
			printf("declare -x %s", tmp->name);
		if (tmp->value)
			printf("=\"%s\"\n", tmp->value);
		else
			printf("\n");
		tmp = tmp->next;
	}
}

t_var	*check_export_args(t_node *args)
{
	t_var	*var;
	t_var	variable;

	var = NULL;
	while (args)
	{
		variable = fill_var(args->token);
		if (!check_for_special_characters(variable))
			ft_varadd_back(&var, ft_varnew(variable));
		args = args->next;
	}
	return (var);
}

void	append_value(t_var *variable)
{
	t_env	*env_idx;
	int		switched;

	switched = 0;
	env_idx = g_global.environment;
	variable->name = ft_strtrim(variable->name, 0, strlen(variable->name) - 2);
	while (env_idx)
	{
		if (!ft_strcmp(env_idx->name, variable->name))
		{
			if (env_idx->value)
				env_idx->value = ft_strunite(env_idx->value, variable->value);
			else
				env_idx->value = variable->value;
			switched = 1;
			break ;
		}
		env_idx = env_idx->next;
	}
	if (!switched)
		ft_envadd_back(&g_global.environment, ft_envnew(*variable));
}

void	insert_value(t_var *variable)
{
	if (ft_getenv(variable->name))
	{
		if (variable->value)
			fill_env_variable(variable->name, variable->value);
	}
	else if (does_env_variable_exist(variable->name))
	{
		fill_env_variable(variable->name, variable->value);
	}
	else
		ft_envadd_back(&g_global.environment, ft_envnew(*variable));
}

int	ft_export(t_smpcmd smpcmd)
{
	t_var	*variable;

	if (smpcmd.args)
	{
		variable = check_export_args(smpcmd.args);
		while (variable)
		{
			if (variable->flag == 1)
				append_value(variable);
			else
				insert_value(variable);
			variable = variable->next;
		}
		if (!g_global.status)
			g_global.status = 0;
		return (2);
	}
	print();
	g_global.status = 0;
	return (2);
}
