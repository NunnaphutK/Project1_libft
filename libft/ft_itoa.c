/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkiticha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 08:25:11 by nkiticha          #+#    #+#             */
/*   Updated: 2023/09/12 09:35:42 by nkiticha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbr_size(int n)
{
	size_t		size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_nbr(int size, int c, int n, char *str)
{
	while (size > c)
	{
		str[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		c;
	size_t		size;

	c = 0;
	size = ft_nbr_size(n);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
		c = 2;
	}
	if (n < 0)
	{
		str[0] = '-';
		c = 1;
		n = -n;
	}
	ft_nbr(size, c, n, str);
	str[size] = '\0';
	return (str);
}
