/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:40:09 by babkar            #+#    #+#             */
/*   Updated: 2022/09/23 17:46:17 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h"

t_env	*ft_envnew(t_var variable)
{
	t_env	*node;

	node = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!node)
		return (node);
	node->name = variable.name;
	node->value = variable.value;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

int	ft_envsize(t_env *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_envadd_back(t_env **lst, t_env *new)
{
	t_env	*temp;

	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		new->next = NULL;
		new->previous = temp;
		temp->next = new;
	}
}
