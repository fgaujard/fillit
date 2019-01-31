/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:14:24 by fgaujard          #+#    #+#             */
/*   Updated: 2018/11/29 17:13:07 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while ((s[start] != '\0') && (i < len))
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
