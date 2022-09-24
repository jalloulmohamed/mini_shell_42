/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 00:35:43 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/24 00:54:02 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_name_file(char *line, int *i)
{
	int		j;
	char	*file_name;
	char	c;

	j = a_e(line,*i);
	file_name = "";
	while (line[j] && ft_strchr("<> ", line[j]) != 1)
	{
		if (line[j] == '\"' || line[j] == '\'')
		{
			c = line[j];
			j++;
			while (line[j] != c && line[j] != '\0')
			{
				file_name = ft_strjoin_char(file_name, line[j]);
				j++;
			}
		}
		else
			file_name = ft_strjoin_char(file_name, line[j]);
		j++;
	}
	*i = j;
	return (file_name);
}

int	input_rederction(char *line, int *index)
{
	char	*name_file;
	int		fd;
	int		j;
	char	*eror;

	j = *index;
	eror = ft_strdup("");
	if (line[j] == '<')
	{
		j++;
		name_file = find_name_file(line, &j);
		fd = open(name_file, O_RDONLY, 0644);
		if (fd < 0)
		{
			eror = ft_strjoin(eror, "minishell :");
			eror = ft_strjoin(eror, name_file);
			eror = ft_strjoin(eror, " No such file or directory");
			ft_putstr_fd(eror, 2);
			return (1);
		}
		dup2(fd, 0);
		close(fd);
	}
	*index = j;
	return (0);
}

int	output_rederction(char *line, int *index)
{
	char	*name_file;
	int		fd;
	int		j;

	j = *index;
	if (line[j] == '>' && line[j + 1] != '>')
	{
		j++;
		name_file = find_name_file(line, &j);
		fd = open(name_file, O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
			return (1);
		dup2(fd, 1);
		close(fd);
	}
	*index = j;
	return (0);
}

int	apend_rederction(char *line, int *index)
{
	char	*name_file;
	int		fd;
	int		j;

	j = *index;
	if (line[j] == '>' && line[j + 1] == '>')
	{
		j += 2;
		name_file = find_name_file(line, &j);
		fd = open(name_file, O_RDONLY | O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd < 0)
			return (1);
		dup2(fd, 1);
		close(fd);
	}
	*index = j;
	return (0);
}
