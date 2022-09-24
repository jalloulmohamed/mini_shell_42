/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:47:42 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/24 00:02:22 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*rederction_cmd(char *line, int *i)
{
	int		j;
	char	*line_red;

	j = 0;
	line_red = "";
	while (line[j])
	{
		if (j == *i)
		{
			if (input_rederction(line, &j))
				return (NULL);
			if (output_rederction(line, &j))
				return (NULL);
			if (apend_rederction(line, &j))
				return (NULL);
		}
		else
		{
			line_red = ft_strjoin_char(line_red, line[j]);
			j++;
		}
	}
	return (line_red);
}

int	find_red(char *line )
{
	int	i;

	i = 0;
	while (line[i])
	{
		scape_paren_quot_in(line, &i);
		if (line[i] == '>' || line[i] == '<')
			return (i);
		i++;
	}
	return (-1);
}

void	red_cmd(char *line)
{
	int	i;
	int	tmd1;
	int	tmd2;

	tmd1 = dup(0);
	tmd2 = dup(1);
	i = 0;
	while (i != -1)
	{
		i = find_red(line);
		if (i != -1)
		{
			line = rederction_cmd(line, &i);
			if (!line)
				return ;
		}
	}
	if (*line)
		if (!builtins(line) && *line)
			sh_execute(line);
	dup2(tmd1, 0);
	dup2(tmd2, 1);
	close(tmd1);
	close(tmd2);
}
