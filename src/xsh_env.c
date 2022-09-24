/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xsh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:25:01 by babkar            #+#    #+#             */
/*   Updated: 2022/09/23 18:22:39 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*xsh_env(char **env)
{
	t_env	*vars;
	int		index;
	t_var	var;

	vars = NULL;
	var = (t_var){NULL, NULL, 0, NULL};
	index = 0;
	while (env[index] != NULL)
	{
		var = fill_var(env[index]);
		ft_envadd_back(&g_global.environment, ft_envnew(var));
		index++;
	}
	if (ft_getenv("SHLVL"))
		fill_env_variable("SHLVL", ft_itoa(ft_atoi(ft_getenv("SHLVL")) + 1));
	else
	{
		var.name = "SHLVL";
		var.value = "1";
		ft_envadd_back(&g_global.environment, ft_envnew(var));
	}
	return (vars);
}
