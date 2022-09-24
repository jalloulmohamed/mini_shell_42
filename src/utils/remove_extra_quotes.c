/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_extra_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:48:53 by babkar            #+#    #+#             */
/*   Updated: 2022/09/23 17:45:56 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h"

int	strlen_without_quotes(char *line)
{
	int		i;
	int		size;
	int		quote;
	int		dquote;

	dquote = 0;
	quote = 0;
	size = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' && dquote % 2 == 0)
			quote++;
		else if (line[i] == '\"' && quote % 2 == 0)
			dquote++;
		else
			size++;
		i++;
	}
	return (size);
}

char	*remove_extra_quotes(char *line)
{
	char	*string;
	int		i;
	int		size;
	int		quote;
	int		dquote;

	i = 0;
	dquote = 0;
	quote = 0;
	size = strlen_without_quotes(line);
	string = (char *)ft_calloc((size + 1), sizeof(char));
	if (!string)
		return (string);
	size = 0;
	while (line[i])
	{
		if (line[i] == '\'' && dquote % 2 == 0)
			quote++;
		else if (line[i] == '\"' && quote % 2 == 0)
			dquote++;
		else
			string[size++] = line[i];
		i++;
	}
	return (string);
}

t_node	*xsh_remove_extra_quotes(t_node *token)
{
	t_node	*tmp;

	tmp = token;
	while (tmp)
	{
		tmp->token = remove_extra_quotes(tmp->token);
		tmp = tmp->next;
	}
	return (token);
}
