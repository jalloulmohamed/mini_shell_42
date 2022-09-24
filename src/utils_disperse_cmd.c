/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_disperse_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 00:31:24 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/24 00:35:21 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	last_parentes(char *line, int j, int i)
{
	j--;
	while (j > i)
	{
		if (line[j] == ')' || line[j] == '(')
			return (line[j]);
		j--;
	}
	return ('0');
}

char	first_parentes(char *line, int i, int j)
{
	i++;
	while (i < j)
	{
		if ((line[i] == ')') || (line[i] == '('))
			return (line[i]);
		i++;
	}
	return ('0');
}

int	check_par(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = (int)ft_strlen(line) -1;
	while (line[i] == ' ' && line[i])
	i++;
	while (j && line[j] == ' ')
		j--;
	if (first_parentes(line, i, j) == ')'
		|| last_parentes(line, j, i) == '(')
		return (0);
	if (line[i] == '(' && line[j] == ')')
	{
		line[i] = ' ';
		line[j] = ' ';
		return (1);
	}
	return (0);
}

char	*after_last_operateur(char *line, int *opp)
{
	int		i;
	char	*c;

	i = (int)ft_strlen(line) -1 ;
	while (i >= 0)
	{
		scape_paren_quot_dec(line, &i);
		if ((line[i] == '|' && line[i - 1] == '|' )
			|| (line[i] == '&' && line[i - 1] == '&'))
		{
			if (line[i] == '|')
				*opp = 1;
			else
				*opp = 2;
			c = ft_substr(line, i + 1, ft_strlen(line) - i);
			line[i - 1] = '\0';
			return (c);
		}
		i--;
	}
	return (NULL);
}
