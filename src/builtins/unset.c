/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:15:03 by babkar            #+#    #+#             */
/*   Updated: 2022/09/25 14:24:48 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtins.h"

void	ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	delete_node(t_env **head, t_env *del)
{
	if (!del->previous)
	{
		if ((*head)->next)
			(*head)->next->previous = NULL;
		*head = del->next;
	}
	else if (!del->next)
		del->previous->next = NULL;
	else
	{
		del->next->previous = del->previous;
		del->previous->next = del->next;
	}
	free(del);
}

int	check_unset_args(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isalpha(arg[0]) && arg[i] >= '0' && arg[i] <= '9')
			return (puterr("not a valid identifier", 1));
		if ((arg[i] < '0' || arg[i] > '9') && (arg[i] < 'A' || arg[i] > 'Z')
			&& (arg[i] < 'a' || arg[i] > 'z') && (arg[i] < '_' || arg[i] > '_'))
			return (puterr("not a valid identifier", 1));
		i++;
	}
	return (0);
}

int	unset(t_smpcmd smpcmd)
{
	char	**var;
	t_env	*env;
	t_node	*args_idx;

	args_idx = smpcmd.args;
	while (args_idx)
	{
		var = ft_split(args_idx->token, '=');
		check_unset_args(args_idx->token);
		env = g_global.environment;
		while (env)
		{
			if (!ft_strcmp(env->name, args_idx->token))
			{
				delete_node(&g_global.environment, env);
				break ;
			}
			env = env->next;
		}
		args_idx = args_idx->next;
	}
	if (!g_global.status)
		g_global.status = 0;
	return (2);
}
