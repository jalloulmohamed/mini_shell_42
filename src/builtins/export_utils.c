/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:58:09 by babkar            #+#    #+#             */
/*   Updated: 2022/09/24 16:09:44 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtins.h"

int	check_for_special_characters(t_var variable)
{
	int	i;

	i = 0;
	while (variable.name[i])
	{
		if (!ft_isalpha(variable.name[0])
			&& variable.name[i] >= '0' && variable.name[i] <= '9')
			return (puterr("not a valid identifier", 1));
		if ((variable.name[i] < '0' || variable.name[i] > '9')
			&& (variable.name[i] < 'A' || variable.name[i] > 'Z')
			&& (variable.name[i] < 'a' || variable.name[i] > 'z')
			&& (variable.name[i] < '_' || variable.name[i] > '_'))
			return (puterr("not a valid identifier", 1));
		i++;
	}
	return (0);
}

t_var	fill_var(char *arg)
{
	int		j;
	int		i;
	t_var	var;

	j = 0;
	while (arg[j] && arg[j] != '=')
		j++;
	if (arg[j] != '=')
	{
		var.name = ft_strtrim(arg, 0, strlen(arg));
		var.value = NULL;
		return (var);
	}
	var.flag = 0;
	i = 1;
	if (arg[j - 1] == '+')
	{
		var.flag = 1;
		i = 2;
	}	
	var.name = ft_strtrim(arg, 0, j - i);
	var.value = ft_strtrim(arg, j + 1, strlen(arg));
	return (var);
}

void	print(void)
{
	if (ft_fork() == 0)
	{
		bubble_sort_dlst(&g_global.environment);
		print_export(g_global.environment);
		exit(0);
	}
	wait(0);
}
