/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:52:10 by babkar            #+#    #+#             */
/*   Updated: 2022/09/25 15:35:18 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
	char			*token;
	struct s_node	*next;
}		t_node;

typedef struct s_pid
{
	int				p;
	struct s_pid	*next;
}		t_pid;

typedef struct s_env
{
	struct s_env	*previous;
	char			*name;
	char			*value;
	struct s_env	*next;
}		t_env;

typedef struct s_var
{
	char			*name;
	char			*value;
	int				flag;
	struct s_var	*next;
}				t_var;

typedef struct s_smpcmd
{
	char	*command;
	char	*option;
	t_node	*args;
}				t_smpcmd;

typedef struct s_garbage
{
	void				*ptr;
	struct s_garbage	*next;
}				t_garbage;

typedef struct s_global
{
	int			status;
	int			exit_status;
	int			running;
	int			heredoc;
	t_env		*environment;
	t_garbage	*garbage;
	t_pid		*pid;
}				t_global;

t_global	g_global;

t_node		*xsh_remove_extra_quotes(t_node *token);
char		*remove_extra_quotes(char *line);

char		*ft_strtrim(char *string, unsigned int start, size_t end);
void		bubble_sort_dlst(t_env **head);

void		ft_varadd_back(t_var **lst, t_var *new);
t_var		*ft_varnew(t_var variable);
t_env		*ft_envnew(t_var variable);

int			ft_envsize(t_env *lst);
void		ft_envadd_back(t_env **lst, t_env *new);

t_node		*ft_nodenew(char *content);
void		ft_nodeadd_back(t_node **lst, t_node *new);
int			nodesize(t_node *lst);

int			ft_isdigit(int c);

char		*ft_itoa(int n);

int			char_count(char *str, char c);

int			ft_atoi(const char *str);

char		*ft_strunite(char *preffix, char *suffix);

char		*ft_substr(char const *s, unsigned int start, size_t len);

int			ft_fork(void);

char		**ft_split(char const *s, char c);

int			ft_strcmp(char *s1, char *s2);

char		*ft_strdup(const char *s1);

void		ft_bzero(void *s, int n);

void		*ft_memset(void *b, int c, size_t len);

void		*ft_calloc(size_t count, size_t size);

size_t		ft_strlen(const char *str);

int			ft_isalpha(int a);

int			puterr(char *str, int status);

void		ft_putstr_fd(char *c, int fd);

int			ft_strchr(const char *s, int c);

char		*ft_strjoin_char(char const *s1, char s2);

char		*ft_strjoin(char const *s1, char const *s2);

void		free_garbage(void);
void		add_to_garbage(void *ptr);
t_garbage	*new_garbage(void *ptr);
t_garbage	*lstlast_garbage(t_garbage *lst);
#endif