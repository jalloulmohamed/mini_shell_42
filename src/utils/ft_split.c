/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:36:45 by babkar            #+#    #+#             */
/*   Updated: 2022/09/23 17:44:03 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.h"

int	wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

int	next_word_len(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

char	**ft_free_tokens(char **t, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(t[j++]);
	free(t);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		f;
	int		i;
	int		j;
	char	**token;

	if (s == NULL)
		return (NULL);
	i = 0;
	f = -1;
	token = (char **)ft_calloc((wordcount(s, c) + 1), sizeof(char *));
	if (!token)
		return (token);
	while (++f < wordcount(s, c))
	{
		j = 0;
		token[f] = (char *)ft_calloc(next_word_len(s, c, i) + 1, sizeof(char));
		if (!token)
			return (ft_free_tokens(token, f));
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
			token[f][j++] = s[i++];
	}
	token[f] = NULL;
	return (token);
}
