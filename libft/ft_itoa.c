/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:47:47 by fgaujard          #+#    #+#             */
/*   Updated: 2018/12/04 16:53:02 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_digit(int n)
{
	int count;

	count = 1;
	if (n < 0)
		count++;
	if (-2147483648 == n)
		return (11);
	if ((-2147483648 < n) && (n < 0))
		n = n * (-1);
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char		*ft_add_digit(char *dest, int size, int j, int n)
{
	int i;

	i = 1;
	while ((n / i) > 9)
		i = i * 10;
	while (j < size)
	{
		dest[j++] = ((n / i) + '0');
		n = n % i;
		i = i / 10;
	}
	dest[j] = '\0';
	return (dest);
}

char			*ft_itoa(int n)
{
	int		j;
	int		size;
	char	*dest;

	size = ft_count_digit(n);
	if (!(dest = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	j = 0;
	if (-2147483648 == n)
	{
		dest[j++] = '-';
		dest[j++] = '2';
		n = 147483648;
	}
	if ((-2147483648 < n) && (n < 0))
	{
		dest[j++] = '-';
		n = n * (-1);
	}
	return (ft_add_digit(dest, size, j, n));
}
