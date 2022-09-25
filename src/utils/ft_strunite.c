/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strunite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:32:48 by babkar            #+#    #+#             */
/*   Updated: 2022/09/25 17:44:10 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h"

char	*ft_strunite(char *preffix, char *suffix)
{
	int		i;
	int		j;
	char	*str;
	int		preffix_len;

	if (preffix)
		preffix_len = ft_strlen(preffix);
	i = 0;
	j = 0;
	if (!suffix)
	{
		suffix = (char *)ft_calloc(1, sizeof(char));
		if (!suffix)
			return (suffix);
	}
	str = (char *)ft_calloc(preffix_len + ft_strlen(suffix) + 1, sizeof(char));
	if (!str)
		return (str);
	while (preffix && preffix[i])
		str[j++] = preffix[i++];
	i = 0;
	while (suffix[i])
		str[j++] = suffix[i++];
	return (str);
}
