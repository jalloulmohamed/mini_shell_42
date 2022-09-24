/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplecommand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:01:35 by babkar            #+#    #+#             */
/*   Updated: 2022/09/23 18:21:23 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	tokenize_command(int *startok, int *endtok, char *line, int *nextok)
{
	int	index;
	int	quote;
	int	dquote;

	quote = 0;
	dquote = 0;
	index = *nextok;
	while (line[index] && line[index] == ' ')
		index++;
	*startok = index;
	while (line[index])
	{
		if (line[index] == '\"')
			dquote++;
		if (line[index] == '\'')
			quote++;
		if (line[index] == ' ' && dquote % 2 == 0 && quote % 2 == 0)
			break ;
		index++;
	}
	*endtok = index - 1;
	while (line[index] && line[index] == ' ')
		index++;
	*nextok = index;
}

t_smpcmd	simplecommand(char *content, t_smpcmd smpcmd)
{
	int			endtok;
	int			startok;
	int			nextok;
	char		*token;
	static int	i;

	startok = 0;
	endtok = 0;
	nextok = 0;
	smpcmd.args = NULL;
	smpcmd.option = NULL;
	while (nextok != (int)ft_strlen(content))
	{
		tokenize_command(&startok, &endtok, content, &nextok);
		token = ft_strtrim(content, startok, endtok);
		if (!i)
			smpcmd.command = token;
		else
			ft_nodeadd_back(&smpcmd.args, ft_nodenew(token));
		i++;
	}
	i = 0;
	return (smpcmd);
}
