/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_dolar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:42:05 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/24 01:59:01 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	scape_s_quot(char *line, int *k)
{
	int		i;
	char	c;

	i = *k;
	if (line[i] == '\'')
	{
		c = line[i];
		i++;
		while (line[i] != c && line[i] != '\0')
			i++;
	}
	*k = i;
}

char	*find_var(char *line, int i)
{
	char	*val;

	val = "";
	i++;
	while (line[i] && (ft_isalpha(line[i]) != 0 || line[i] == '?' ))
	{
		val = ft_strjoin_char(val, line[i]);
		i++;
	}
	return (val);
}

char	*replase_dolar(char *line, int i, char *var, char *value)
{
	int		j;
	char	*c_dolar;

	j = 0;
	c_dolar = "";
	while (line[j])
	{
		if (j == i)
		{
			j++;
			while (ft_isalpha(line[j]) != 0 && line[j])
				j++;
			if (var[0] == '?')
			{
				c_dolar = ft_strjoin(c_dolar, ft_itoa(g_global.status));
				j++;
			}
			else if (value)
				c_dolar = ft_strjoin(c_dolar, value);
		}
		if (j < (int) ft_strlen(line))
			c_dolar = ft_strjoin_char(c_dolar, line[j]);
		j++;
	}
	return (c_dolar);
}

int	find_first_dolar(char *line, int l)
{
	int	i;

	i = l;
	while (line[i])
	{
		scape_s_quot(line, &i);
		if (line[i] == '\"')
		{
			i++;
			while (line[i] != '\"' && line[i] != '\0')
			{
				if (line[i] == '$' && line[i + 1] == '$')
					i++;
				else if (line[i] == '$' && line[i + 1] != '$')
					return (i);
				i++;
			}
		}
		if (line[i] == '$' && line[i + 1] == '$')
			i++;
		else if (line[i] == '$' && line[i + 1] != '$' && line[i + 1])
			return (i);
		i++;
	}
	return (-1);
}

char	*expend_dolar(char *line)
{
	int		i;
	char	*var;
	char	*value;

	i = 0;
	while (i != -1)
	{
		i = find_first_dolar(line, i);
		if (i != -1)
		{
			var = find_var(line, i);
			value = ft_getenv(var);
			line = replase_dolar(line, i, var, value);
		}
	}
	return (line);
}
