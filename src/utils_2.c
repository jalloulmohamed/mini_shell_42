/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 00:27:08 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/24 00:35:28 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	scape_t_d_s_qout(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '\"' && line[i + 1] == '\"')
			|| (line[i] == '\'' && line[i + 1] == '\''))
		{
		line[i] = ' ';
		line[i + 1] = ' ';
		i += 2;
		}
		scape_s_d_quot(line, &i);
		i++;
	}
	return ;
}

void	scape_s_d_quot_dec(char *line, int *k)
{
	int		i;
	char	c;

	i = *k;
	if (line[i] == '\"' || line[i] == '\'')
	{
		c = line[i];
		i--;
		while (line[i] != c && i != 0)
		i--;
	}
	*k = i;
}

void	scape_paren_quot_dec(char *line, int *k)
{
	int	i;
	int	j;

	i = *k;
	j = 0;
	scape_s_d_quot_dec(line, &i);
	if (line[i] == ')')
	{
		while (1)
		{
			if (line[i] == ')')
				j++;
			if (line[i] == '(')
				j--;
			if (line[i] == '(' && j == 0)
				break ;
			i--;
		}
	}
	*k = i;
}
