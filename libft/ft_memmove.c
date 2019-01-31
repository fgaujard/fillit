/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:29:16 by fgaujard          #+#    #+#             */
/*   Updated: 2018/11/27 18:07:06 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sr;
	unsigned char	*dst;

	i = 0;
	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (sr < dst)
		while (++i <= n)
			dst[n - i] = sr[n - i];
	else
		while (n > 0)
		{
			dst[i] = sr[i];
			i++;
			n--;
		}
	return (dest);
}
