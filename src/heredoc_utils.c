/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:40:08 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/24 16:33:27 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*name(void)
{
	static int	n;

	n++;
	return (ft_itoa(n));
}

int	find_first_heredoc(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		scape_s_d_quot(line, &i);
		if (line[i] == '<' && line[i + 1] == '<')
			return (i);
		i++;
	}
	return (-1);
}

void	sigint_handler_child(int sum)
{
	(void)sum;
	g_global.heredoc = 0;
	rl_done = 1;
}

int	event(void)
{
	return (0);
}

int	read_heredoc(char *del, int fd)
{
	char	*line_inp;

	signal(SIGINT, sigint_handler_child);
	rl_event_hook = event;
	while (g_global.heredoc)
	{
		line_inp = readline(">");
		if (!line_inp)
			break ;
		add_to_garbage(line_inp);
		if (!ft_strcmp(line_inp, del))
			break ;
		ft_putstr_fd(line_inp, fd);
	}
	if (g_global.heredoc == 0)
		return (1);
	return (0);
}
