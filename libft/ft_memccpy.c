/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:25:10 by fgaujard          #+#    #+#             */
/*   Updated: 2018/11/30 18:59:06 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sr;
	size_t			i;

	i = 0;
	dst = (unsigned char *)(dest);
	sr = (unsigned char *)(src);
	while (i < n)
	{
		dst[i] = sr[i];
		if (dst[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
