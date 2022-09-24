/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:36:02 by babkar            #+#    #+#             */
/*   Updated: 2022/09/24 16:14:12 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_args(t_smpcmd smpcmd)
{
	int		size;
	t_node	*index;
	int		i;
	char	**args;

	i = 1;
	index = smpcmd.args;
	size = nodesize(smpcmd.args);
	args = (char **)ft_calloc(size + 1 + 1, sizeof(char *));
	if (!args)
		return (NULL);
	args[size + 1] = NULL;
	args[0] = ft_strdup(smpcmd.command);
	while (index && i < size + 1)
	{
		args[i] = ft_strdup(index->token);
		index = index->next;
		i++;
	}
	return (args);
}

char	**xsh_path(void)
{
	char	**path;
	int		i;

	i = 0;
	path = ft_split(ft_getenv("PATH"), ':');
	if (!path)
		return (NULL);
	while (path[i] != NULL)
	{
		path[i] = ft_strunite(path[i], "/");
		i++;
	}
	return (path);
}

void	sh_execute(char *line)
{
	t_smpcmd	smpcmd;
	char		**args;

	smpcmd = (t_smpcmd){NULL, NULL, NULL};
	smpcmd = simplecommand(line, smpcmd);
	smpcmd.command = remove_extra_quotes(smpcmd.command);
	smpcmd.args = xsh_remove_extra_quotes(smpcmd.args);
	args = get_args(smpcmd);
	if (check_par(line))
		ex_sub_shell(line);
	else if (!builtins(line))
		ex_excve(line, smpcmd, args);
}
