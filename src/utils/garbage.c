/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:45:42 by babkar            #+#    #+#             */
/*   Updated: 2022/09/23 17:45:47 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h"

t_garbage	*lstlast_garbage(t_garbage *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
	{
		lst = lst -> next;
	}
	return (lst);
}

t_garbage	*new_garbage(void *ptr)
{
	t_garbage	*p;

	p = (t_garbage *)malloc(sizeof(t_garbage));
	if (!p)
		return (0);
	p->ptr = ptr;
	p->next = NULL;
	return (p);
}

void	add_to_garbage(void *ptr)
{
	t_garbage	*new;
	t_garbage	*tmp;

	new = new_garbage(ptr);
	if (g_global.garbage)
	{
		tmp = lstlast_garbage((g_global.garbage));
		tmp->next = new;
	}
	else
		g_global.garbage = new;
}

void	free_garbage(void)
{
	t_garbage	*tem;

	while (g_global.garbage)
	{
		tem = g_global.garbage;
		g_global.garbage = (g_global.garbage)->next;
		if (tem->ptr)
			free(tem->ptr);
		free(tem);
	}
}
