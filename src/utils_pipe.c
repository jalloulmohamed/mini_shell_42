/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 01:07:34 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/25 17:48:38 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_pid	*lstlast_pid(t_pid *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
	{
		lst = lst -> next;
	}
	return (lst);
}

t_pid	*new_pid(int ptr)
{
	t_pid	*p;

	p = (t_pid *)malloc(sizeof(t_pid));
	if (!p)
		return (0);
	add_to_garbage(p);
	p->p = ptr;
	p->next = NULL;
	return (p);
}

void	add_pid(int p)
{
	t_pid	*new;
	t_pid	*tmp;

	new = new_pid(p);
	if (g_global.pid)
	{
		tmp = lstlast_pid((g_global.pid));
		tmp->next = new;
	}
	else
		g_global.pid = new;
}
