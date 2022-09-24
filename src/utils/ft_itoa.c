/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:14:53 by babkar            #+#    #+#             */
/*   Updated: 2022/09/23 18:15:41 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h" 

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_convert(char *p, int n, int lenp)
{
	int	k;

	k = 0;
	if (n < 0)
	{
		p[0] = '-';
		k++;
		n = n * -1;
	}
	while (n != 0)
	{
		p[lenp - 1] = (n % 10) + 48;
		n = n / 10;
		k++;
		lenp--;
	}
	p[k] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	int		i;
	int		k;
	char	*p;

	k = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_intlen(n);
	p = (char *) malloc(sizeof(char) * (i + 1));
	if (!p)
		return (0);
	add_to_garbage(p);
	return (ft_convert(p, n, i));
}
