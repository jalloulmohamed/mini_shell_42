/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:08:53 by babkar            #+#    #+#             */
/*   Updated: 2022/09/23 14:56:47 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtins.h"

int	builtins(char *line)
{
	t_smpcmd	smpcmd;

	smpcmd = (t_smpcmd){NULL, NULL, NULL};
	smpcmd = simplecommand(line, smpcmd);
	smpcmd.command = remove_extra_quotes(smpcmd.command);
	smpcmd.args = xsh_remove_extra_quotes(smpcmd.args);
	if (!ft_strcmp("env", smpcmd.command))
		return (envt(smpcmd));
	if (!ft_strcmp("export", smpcmd.command))
		return (ft_export(smpcmd));
	if (!ft_strcmp("unset", smpcmd.command))
		return (unset(smpcmd));
	if (!ft_strcmp("exit", smpcmd.command))
		ft_exit(smpcmd);
	if (!ft_strcmp("pwd", smpcmd.command))
		return (pwd());
	if (!ft_strcmp("cd", smpcmd.command))
		return (cd(smpcmd));
	if (!ft_strcmp("echo", smpcmd.command))
		return (echo(smpcmd));
	return (0);
}
