/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:17:16 by fgaujard          #+#    #+#             */
/*   Updated: 2018/11/30 19:00:24 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sr;

	i = 0;
	dest = (unsigned char *)dst;
	sr = (unsigned char *)src;
	while (i < n)
	{
		dest[i] = sr[i];
		i++;
	}
	return (dst);
}
