/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiticha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:28:15 by nkiticha          #+#    #+#             */
/*   Updated: 2023/09/11 15:03:50 by nkiticha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		cc;
	char		*ss;

	i = ft_strlen(s);
	cc = (char)c;
	ss = (char *)s;
	while (i > 0)
	{
		if (ss[i] == cc)
			return (&ss[i]);
		i--;
	}
	if (ss[i] == cc)
		return (&ss[i]);
	return (NULL);
}
