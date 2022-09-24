/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xsh_signals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:31:17 by babkar            #+#    #+#             */
/*   Updated: 2022/09/24 16:28:49 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sigint_handler(int sum)
{
	if (!sum)
		return ;
	if (g_global.running == 0)
	{
		write(2, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_global.status = 130;
	}
	else if (g_global.running == 1)
	{
		printf("\n");
	}
}

void	sigquit_handler(int sum)
{
	if (!sum)
		return ;
	if (g_global.running == 0)
		return ;
	if (g_global.running == 1 && g_global.heredoc == 0)
		printf("Quit: 3\n");
}

void	exit_status(void)
{
	if (WIFEXITED(g_global.exit_status))
		g_global.status = WEXITSTATUS(g_global.exit_status);
	if (WIFSIGNALED(g_global.exit_status))
		g_global.status = 128 + WTERMSIG(g_global.exit_status);
}

void	handling_signals(void)
{
	struct sigaction	quit;
	struct sigaction	sigint;

	quit.sa_handler = sigquit_handler;
	sigemptyset(&quit.sa_mask);
	quit.sa_flags = SA_RESTART;
	sigint.sa_handler = sigint_handler;
	sigemptyset(&sigint.sa_mask);
	sigint.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &quit, NULL);
	sigaction(SIGINT, &sigint, NULL);
	rl_catch_signals = 0;
}
