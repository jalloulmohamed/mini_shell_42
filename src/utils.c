/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 00:54:44 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/25 17:03:43 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	b_e(char *line, int index)
{
	int	i;

	i = index;
	if (i > 0)
	{
		while (i)
		{
			if (line[i] != ' ')
				return (i);
			i--;
		}
	}
	return (index);
}

int	a_e(char *line, int index)
{
	int	i;

	i = index;
	while (line[i])
	{
		if (line[i] != ' ')
			return (i);
		i++;
	}
	return (index);
}

void	scape_s_d_quot(char *line, int *k)
{
	int		i;
	char	c;

	i = *k;
	if (line[i] == '\"' || line[i] == '\'')
	{
		c = line[i];
		i++;
		while (line[i] != c && line[i] != '\0')
			i++;
	}
	*k = i;
}

void	scape_paren_quot_in(char *line, int *k)
{
	int	i;
	int	j;

	i = *k;
	j = 0;
	scape_s_d_quot(line, &i);
	if (line[i] == '(')
	{
		while (1)
		{
			if (line[i] == '(')
				j++;
			if (line[i] == ')')
				j--;
			if (line[i] == ')' && j == 0)
				break ;
			i++;
		}
	}
	*k = i;
}
