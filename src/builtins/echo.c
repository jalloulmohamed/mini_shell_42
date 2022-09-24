/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:39:51 by babkar            #+#    #+#             */
/*   Updated: 2022/09/24 20:11:42 by mjalloul         ###   ########.fr       */
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

int	only_this_character(char *line, char c)
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

t_smpcmd	check_option(t_smpcmd smpcmd)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (smpcmd.args->next && smpcmd.args->token[0] == '-'
		&& !only_this_character(ft_strtrim(smpcmd.args->next->token, 1,
				ft_strlen(smpcmd.args->next->token)), 'n'))
		smpcmd.args = smpcmd.args->next;
	printf("%s\n", smpcmd.args->token);
	if (smpcmd.args->token[0] == '-')
	{
		i++;
		while (smpcmd.args->token[i] && smpcmd.args->token[i] == 'n')
		{
			j++;
			i++;
		}
		if (j && smpcmd.args->token[i] == '\0')
		{
			smpcmd.option = "-n";
			smpcmd.args = smpcmd.args->next;
		}
	}
	return (smpcmd);
}

int	echo(t_smpcmd smpcmd)
{
	if (!smpcmd.args)
	{
		printf("\n");
		return (2);
	}
	smpcmd = check_option(smpcmd);
	print_args(smpcmd);
	g_global.status = 0;
	return (2);
}
