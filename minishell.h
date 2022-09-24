/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 00:58:28 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/24 16:43:11 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "builtins.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>

char		*ft_strjoin_char(char const *s1, char s2);
// minishell
int			syntaxe1_eror(char *line);
int			syntaxe2_eror(char *line);
void		lvl_and_or(char *line);
void		lvl_pipe(char *list_cmd);
char		*expend_heredoc(char *line);

// rederection
void		red_cmd(char *line);
int			input_rederction(char *line, int *index);
int			output_rederction(char *line, int *index);
int			apend_rederction(char *line, int *index);

// heredoc utils
int			find_first_heredoc(char *line);
char		*name(void);
int			read_heredoc(char *del, int fd);

// utls disperse
char		last_parentes(char *line, int j, int i);
char		first_parentes(char *line, int i, int j);
int			check_par(char *line);
char		*after_last_operateur(char *line, int *opp);

// utils
int			b_e(char *line, int index);
int			a_e(char *line, int index);
void		scape_s_d_quot(char *line, int *k);
void		scape_paren_quot_dec(char *line, int *k);
void		scape_paren_quot_in(char *line, int *k);
void		scape_t_d_s_qout(char *line);

// expend Dolar
char		*expend_dolar(char *line);

// expend wildcards
char		*expend_wildcards(char *line);
// pid pipe

t_pid		*lstlast_pid(t_pid *lst);
t_pid		*new_pid(int ptr);
void		add_pid(int p);

t_smpcmd	simplecommand(char *content, t_smpcmd smpcmd);
t_env		*xsh_env(char **env);
void		handling_signals(void);
void		exit_status(void);
char		**xsh_path(void);
// exuc
char		*command_path(t_smpcmd smpcmd);
void		sh_execute(char *line);
int			nodesize(t_node *lst);
void		ex_excve(char *line, t_smpcmd smpcmd, char **args);
void		ex_sub_shell(char *line);

#endif