/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:56:46 by babkar            #+#    #+#             */
/*   Updated: 2022/09/23 18:05:07 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s))
		p = (char *)malloc(sizeof(*s) * (ft_strlen(s) - start + 1));
	else
		p = (char *)malloc(sizeof(*s) * (len + 1));
	if (!p)
		return (0);
	add_to_garbage(p);
	while (s[start] && len--)
	{	
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
