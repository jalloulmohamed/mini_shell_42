/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:39:51 by babkar            #+#    #+#             */
/*   Updated: 2022/09/25 15:35:01 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtins.h"

void	print_args(t_smpcmd smpcmd)
{
	int		i;
	t_node	*args_idx;

	args_idx = smpcmd.args;
	i = 0;
	while (args_idx)
	{
		if (i)
			printf(" ");
		printf("%s", args_idx->token);
		args_idx = args_idx->next;
		i++;
	}
	if (!smpcmd.option)
		printf("\n");
}

int	only_char(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != c)
			return (1);
		i++;
	}
	return (0);
}

t_smpcmd	insert_option(t_smpcmd scmd)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (scmd.args->token[0] == '-' && !only_char(ft_strtrim(scmd.args->token, \
	1, ft_strlen(scmd.args->token)), 'n'))
	{
		i++;
		while (scmd.args->token[i] && scmd.args->token[i] == 'n')
		{
			j++;
			i++;
		}
		if (j && scmd.args->token[i] == '\0')
		{
			scmd.option = "-n";
			scmd.args = scmd.args->next;
		}
	}	
	return (scmd);
}

t_smpcmd	check_option(t_smpcmd scmd)
{
	char	*token;
	char	*next_token;

	token = ft_strtrim(scmd.args->token, 1, ft_strlen(scmd.args->token));
	if (scmd.args->next)
		next_token = ft_strtrim(scmd.args->next->token, \
		1, ft_strlen(scmd.args->next->token));
	while (scmd.args->next && scmd.args->token[0] == '-'
		&& scmd.args->next->token[0] == '-' && !only_char(next_token, 'n')
		&& !only_char(token, 'n'))
		scmd.args = scmd.args->next;
	scmd = insert_option(scmd);
	return (scmd);
}

int	echo(t_smpcmd smpcmd)
{
	if (smpcmd.args == NULL)
	{
		printf("\n");
		return (2);
	}
	smpcmd = check_option(smpcmd);
	print_args(smpcmd);
	g_global.status = 0;
	return (2);
}
