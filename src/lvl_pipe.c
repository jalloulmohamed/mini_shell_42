/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:16:11 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/24 14:46:10 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*befor_first_pipe(char *line, int *k)
{
	int		i;
	char	*c;
	int		f;

	f = *k;
	i = *k;
	while (line[i])
	{
		scape_paren_quot_in (line, &i);
		if (line[i] == '|' && line[i + 1] != '|')
		{
			c = ft_substr(line, f, i - f);
			line[i] = ' ';
			*k = i;
			return (c);
		}
		i++;
	}
	if (line[i] == '\0')
		i = -1;
	*k = i;
	return (ft_substr(line, f, ft_strlen(line)));
}

int	checkpipe(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		scape_paren_quot_in(line, &i);
		if ((line[i] == '|' && line[i + 1] != '|'))
			return (1);
		i++;
	}
	return (0);
}

void	child_pipe(char *first_cmd_pipe, int len, int *fd)
{
	if (len != -1)
		dup2(fd[1], 1);
	close(fd[1]);
	close(fd[0]);
	red_cmd(expend_dolar(first_cmd_pipe));
}

int	pipe_cmd(char *line, int p)
{
	char	*first_cmd_pipe;
	int		len;
	int		fd[2];

	len = 0;
	while (len != -1)
	{
		first_cmd_pipe = befor_first_pipe(line, &len);
		pipe(fd);
		p = fork();
		if (!p)
		{
			child_pipe(first_cmd_pipe, len, fd);
			if (g_global.status == 0)
				exit(0);
			else
				exit(127);
		}
		add_pid(p);
		dup2(fd[0], 0);
		close(fd[1]);
		close(fd[0]);
	}
	return (p);
}

void	lvl_pipe(char *line)
{
	int	tmp_fd;
	int	p;

	p = 0;
	if (!checkpipe(line))
		red_cmd(expend_dolar(line));
	else
	{
		tmp_fd = dup(0);
		p = pipe_cmd(line, p);
		close(0);
		dup2(tmp_fd, 0);
		while (g_global.pid)
		{
			if (g_global.pid->p == p)
				waitpid (g_global.pid->p, &g_global.exit_status, 0);
			else
				waitpid (g_global.pid->p, 0, 0);
			g_global.pid = g_global.pid->next;
		}
		g_global.status = WEXITSTATUS(g_global.exit_status);
		close(tmp_fd);
	}
}
