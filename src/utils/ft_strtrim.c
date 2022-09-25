/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:13:27 by babkar            #+#    #+#             */
/*   Updated: 2022/09/25 17:44:15 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h"

char	*ft_strtrim(char *string, unsigned int start, size_t end)
{
	char	*substring;
	size_t	j;

	if (!string)
		return (string);
	substring = (char *)ft_calloc((end - start + 2), sizeof(char));
	if (!substring)
		return (substring);
	j = 0;
	if (start <= (unsigned int)ft_strlen(string))
		while (string[start] && start <= end)
			substring[j++] = string[start++];
	return (substring);
}
