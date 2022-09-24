/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 01:51:42 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/24 16:45:43 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*delmeteur(char *line, int *k, char *del)
{
	char	c;
	int		i;

	i = *k;
	while (ft_strchr(" <>|&", line[i]) != 1 && line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			c = line[i];
			i++;
			while (line[i] != c && line[i] != '\0')
			{
				del = ft_strjoin_char(del, line[i]);
				i++;
			}
			i++;
		}
		else
		{
			del = ft_strjoin_char(del, line[i]);
			i++;
		}
	}
	*k = i;
	return (del);
}

char	*find_del(char *line, int *k)
{
	int		i;
	char	*del;

	del = ft_strdup("");
	i = *k;
	if (line[i] == '<' && line[i + 1] == '<')
	{
		i++;
		i = a_e(line, i + 1);
		del = delmeteur(line, &i, del);
		if (line[a_e(line, i)] == '<' && line[a_e(line, i) + 1] == '<')
		{
			while (line[i] != '<' )
				i++;
		}
		*k = i;
		return (del);
	}
	return (NULL);
}

char	*make_cmd(char *line, int k, int i, char *file_n)
{
	int		j;
	char	*s;

	j = 0;
	s = ft_strdup("");
	while (line[j])
	{
		if (j == k)
		{
			s = ft_strjoin(s, "< ");
			s = ft_strjoin(s, file_n);
			j = i;
		}
		if (line[j] != '\0')
		{
			s = ft_strjoin_char(s, line[j]);
			j++;
		}
	}
	return (s);
}

char	*replace_heredoc(char *line, int i)
{
	int		fd;
	char	*del;
	int		k;
	char	*fn;

	k = i;
	fn = ft_strjoin(ft_strjoin("/tmp/", name()), "_her");
	while (g_global.heredoc)
	{
		del = find_del(line, &i);
		if (!del)
			break ;
		fd = open(fn, O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (read_heredoc(del, fd) == 1)
		{
			unlink(fn);
			fn = ft_strjoin(ft_strjoin("/tmp/", name()), "_her");
			fd = open(fn, O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, 0644);
			close(fd);
		}
		close(fd);
	}
	return (make_cmd(line, k, i, fn));
}

char	*expend_heredoc(char *line)
{
	int	i;

	i = 0;
	g_global.heredoc = 1;
	while (i != -1 && g_global.heredoc)
	{
		i = find_first_heredoc(line);
		if (i != -1 && g_global.heredoc)
			line = replace_heredoc(line, i);
	}
	if (g_global.heredoc == 0)
	{
		g_global.status = 1;
		return (NULL);
	}
	return (line);
}
