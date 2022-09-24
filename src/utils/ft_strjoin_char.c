/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:18:53 by babkar            #+#    #+#             */
/*   Updated: 2022/09/23 18:19:17 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h"

char	*ft_strjoin_char(char const *s1, char s2)
{
	char	*p;
	size_t	i;
	int		j;

	j = 0;
	if (s1 != NULL && s2)
		i = ft_strlen(s1) + 1;
	else
		return (0);
	p = (char *)malloc(i + 1);
	if (!p)
		return (0);
	add_to_garbage(p);
	while (s1[j])
		*p++ = s1[j++];
	*p++ = s2;
	*p = '\0';
	return (p - i);
}
