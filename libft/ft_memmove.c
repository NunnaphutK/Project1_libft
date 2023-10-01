/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiticha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:18:46 by nkiticha          #+#    #+#             */
/*   Updated: 2023/09/11 16:16:52 by nkiticha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dd;
	unsigned char	*ss;

	i = 0;
	dd = (unsigned char *)dst;
	ss = (unsigned char *)src;
	if (!dd && !ss)
		return (NULL);
	if (dd < ss)
	{
		return (ft_memcpy(dd, ss, len));
	}
	while (len > 0)
	{
		dd[len - 1] = ss[len - 1];
		len--;
	}
	return (dd);
}
