/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiticha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:15:34 by nkiticha          #+#    #+#             */
/*   Updated: 2023/09/12 00:49:59 by nkiticha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ss;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		ss = (char *)malloc(1);
		if (ss != NULL)
			ss[0] = '\0';
		return (ss);
	}
	i = ft_strlen(&s[start]);
	if (i > len)
		i = len;
	i += 1;
	ss = (char *)malloc(sizeof(char) * i);
	if (ss == NULL)
		return (NULL);
	ft_strlcpy(ss, &s[start], i);
	return (ss);
}
