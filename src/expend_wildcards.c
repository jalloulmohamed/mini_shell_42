/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_wildcards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:29:11 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/24 16:42:56 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*open_dir(char *line, char *path)
{
	DIR				*d;
	struct dirent	*dir;
	char			*list_dir;

	(void) line;
	d = opendir(path);
	list_dir = "";
	if (d)
	{
		dir = readdir(d);
		while (dir != NULL)
		{
			if (dir -> d_name[0] != '.')
				list_dir = ft_strjoin(ft_strjoin(list_dir, " "), dir->d_name);
			dir = readdir(d);
		}
		closedir(d);
	}
	return (list_dir);
}

char	*replace_wild(char *line, char *path)
{
	char	*line_wild;
	int		j;

	j = 0;
	line_wild = "";
	while (line[j])
	{
		if (line[j] == '*')
		{
			while (line[j] == '*' && line[j])
				j++;
			line_wild = ft_strjoin(line_wild, open_dir(line, path));
		}
		if (j < (int)ft_strlen(line))
			line_wild = ft_strjoin_char(line_wild, line[j]);
		j++;
	}
	return (line_wild);
}

int	find_wild(char *line )
{
	int	i;

	i = 0;
	while (line[i])
	{
		scape_paren_quot_in(line, &i);
		if (line[i] == '*')
			return (i);
		i++;
	}
	return (-1);
}

char	*expend_wildcards(char *line)
{
	int			i;
	char		cwd[PATH_MAX];
	char		*path;

	path = getcwd(cwd, sizeof(cwd));
	i = 0;
	while (i != -1)
	{
		i = find_wild(line);
		if (i != -1)
			line = replace_wild(line, path);
	}
	return (line);
}
