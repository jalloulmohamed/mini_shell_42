/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:47:06 by babkar            #+#    #+#             */
/*   Updated: 2022/09/23 16:23:06 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtins.h"

char	*ft_getenv(char *name)
{
	char	*value;
	t_env	*environment;

	environment = g_global.environment;
	value = NULL;
	while (environment)
	{
		if (!ft_strcmp(environment->name, name))
		{
			value = environment->value;
			break ;
		}
		environment = environment->next;
	}
	return (value);
}

void	fill_env_variable(char *name, char *value)
{
	t_env	*env;

	env = g_global.environment;
	while (env)
	{
		if (!ft_strcmp(env->name, name))
		{
			if (value)
				env->value = strdup(value);
			else
				env->value = value;
			break ;
		}
		env = env->next;
	}
}

int	does_env_variable_exist(char *name)
{
	t_env	*environment;

	environment = g_global.environment;
	while (environment)
	{
		if (!ft_strcmp(environment->name, name))
			return (1);
		environment = environment->next;
	}
	return (0);
}
