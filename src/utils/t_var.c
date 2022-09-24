/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_var.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:54:21 by babkar            #+#    #+#             */
/*   Updated: 2022/09/23 17:46:43 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h"

t_var	*ft_varnew(t_var variable)
{
	t_var	*node;

	node = (t_var *)ft_calloc(1, sizeof(t_var));
	if (!node)
		return (NULL);
	node->name = variable.name;
	node->value = variable.value;
	node->flag = variable.flag;
	node->next = NULL;
	return (node);
}

void	ft_varadd_back(t_var **lst, t_var *new)
{
	t_var	*temp;

	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
