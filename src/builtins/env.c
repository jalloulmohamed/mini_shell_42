/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 08:59:30 by babkar            #+#    #+#             */
/*   Updated: 2022/09/23 16:23:06 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtins.h"

int	envt(t_smpcmd smpcmd)
{
	t_env	*env;

	if (smpcmd.args)
		return (puterr("No such file or directory", 127));
	env = g_global.environment;
	while (env)
	{
		if (env->name && env->value)
			printf("%s=%s\n", env->name, env->value);
		env = env->next;
	}
	g_global.status = 0;
	return (2);
}
