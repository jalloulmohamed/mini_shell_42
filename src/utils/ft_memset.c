/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:47:58 by babkar            #+#    #+#             */
/*   Updated: 2022/09/23 17:43:22 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*string;
	size_t				i;

	i = 0;
	string = (unsigned char *)b;
	while (i < len)
		string[i++] = (unsigned char)c;
	return (b);
}
