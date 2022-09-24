/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_and_or.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:51:26 by mjalloul          #+#    #+#             */
/*   Updated: 2022/09/23 23:44:45 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	lvl_and_or(char *line)
{
	int		i;
	char	*last_cmd;

	last_cmd = after_last_operateur(line, &i);
	if (last_cmd)
	{
		lvl_and_or(line);
		if (g_global.status != 0 && i == 1)
			lvl_pipe(last_cmd);
		if (g_global.status == 0 && i == 2)
			lvl_pipe(last_cmd);
	}
	else
		lvl_pipe(line);
}
