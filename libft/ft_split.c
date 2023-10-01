/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiticha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:15:42 by nkiticha          #+#    #+#             */
/*   Updated: 2023/09/20 21:25:35 by nkiticha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countw(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (s == 0)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != 0)
			cnt++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (cnt);
}

static char	ft_free(size_t word, char **result)
{
	if (result[word])
		return (0);
	while (word > 0)
	{
		free(result[word - 1]);
		word--;
	}
	free(result);
	return (1);
}

static char	**ft_mallocstr(char const *s, char c, char **result)
{
	size_t	word;
	size_t	i;
	size_t	j;

	word = 0;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			j++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			result[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (ft_free(word, result) == 1)
				return (NULL);
			ft_strlcpy(result[word], &s[i - j + 1], j + 1);
			word++;
			j = 0;
		}
		i++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	cnt;

	if (s == NULL)
		return (NULL);
	cnt = ft_countw(s, c);
	result = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (result == 0)
		return (0);
	result[cnt] = NULL;
	return (ft_mallocstr(s, c, result));
}
