/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort_dlst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:05:42 by babkar            #+#    #+#             */
/*   Updated: 2022/09/23 15:46:37 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h"

static void	swap(t_env **ptr1, t_env **ptr2)
{
	t_env	tmp;

	tmp.name = (*ptr2)->name;
	tmp.value = (*ptr2)->value;
	(*ptr2)->name = (*ptr1)->name;
	(*ptr2)->value = (*ptr1)->value;
	(*ptr1)->name = tmp.name;
	(*ptr1)->value = tmp.value;
}

void	bubble_sort_dlst(t_env **head)
{
	t_env	**h;
	t_env	*tmp_h;
	int		swapped;

	while (1)
	{
		h = head;
		tmp_h = *h;
		swapped = 0;
		while (tmp_h->next != NULL)
		{
			if (ft_strcmp(tmp_h->name, tmp_h->next->name) > 0)
			{
				swap(&tmp_h, &tmp_h->next);
				swapped = 1;
			}
			tmp_h = tmp_h->next;
		}
		if (swapped == 0)
			break ;
	}
}
