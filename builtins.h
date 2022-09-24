/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:53:35 by babkar            #+#    #+#             */
/*   Updated: 2022/09/24 16:24:44 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "utils.h"
# include <sys/syslimits.h>
# include <errno.h>
# include <sys/types.h> // stat lstat fstat
# include <sys/stat.h> // stat lstat fstat
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

int			does_env_variable_exist(char *name);
void		fill_env_variable(char *name, char *value);
char		*ft_getenv(char *name);
int			builtins(char *line);
int			cd(t_smpcmd smpcmd);
int			echo(t_smpcmd smpcmd);
int			envt(t_smpcmd smpcmd);
int			ft_exit(t_smpcmd smpcmd);
int			ft_export(t_smpcmd smpcmd);
t_var		fill_var(char *arg);
int			check_for_special_characters(t_var variable);
int			pwd(void);
int			unset(t_smpcmd smpcmd);
int			ft_strcmp(char *s1, char *s2);
t_node		*xsh_dolar_expansion(t_node *token, t_env *env);
t_smpcmd	simplecommand(char *content, t_smpcmd smpcmd);
void		print(void);
void		print_export(t_env *env);
#endif
