/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:33:42 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/24 16:43:48 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*sh_readline(char *prompt)
{
	char	*line;

	line = readline(prompt);
	if (line == NULL)
		exit(1);
	add_to_garbage(line);
	if (ft_strlen(line) > 0)
		add_history(line);
	return (line);
}

void	sh_loop(void)
{
	char		*line;

	while (1)
	{	
		handling_signals();
		line = sh_readline("Minishell> ");
		if (*line)
		{
			g_global.running = 0;
			scape_t_d_s_qout(line);
			if (syntaxe1_eror(line) == 1 || syntaxe2_eror(line) == 1)
			{
				ft_putstr_fd("Minishell : Syntaxe_error", 2);
				g_global.status = 258;
			}
			else
			{
				line = expend_heredoc(line);
				if (line)
					lvl_and_or(expend_wildcards(line));
			}
		}
	}
}

int	main(int ac, char **av, char **env)
{
	if (ac != 1 && av[1] != NULL)
		return (1);
	xsh_env(env);
	sh_loop();
	free_garbage();
}
