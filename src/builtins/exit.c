/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:02:34 by babkar            #+#    #+#             */
/*   Updated: 2022/09/23 15:13:15 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtins.h"

int	check_exit_args(const char *str)
{
	int	num;
	int	sign;
	int	i;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
		sign *= (-1);
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			puterr("xsh: exit: numeric argument required", 1);
			exit(255);
		}
		num = num * 10 + (str[i++] - 48);
	}
	return (num * sign);
}

int	ft_nodesize(t_node *node)
{
	int	i;

	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

int	ft_exit(t_smpcmd smpcmd)
{
	t_node	*args_idx;
	int		nbr;

	nbr = 0;
	args_idx = smpcmd.args;
	printf("exit\n");
	if (!smpcmd.args)
		exit(0);
	nbr = check_exit_args(args_idx->token);
	if (ft_nodesize(smpcmd.args) > 1)
		return (puterr("xsh: exit: too many arguments", 1));
	if (nbr <= -1)
		exit(256 + (nbr % 256));
	exit(nbr % 256);
	return (2);
}
