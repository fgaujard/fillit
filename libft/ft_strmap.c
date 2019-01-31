/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:04:56 by fgaujard          #+#    #+#             */
/*   Updated: 2018/11/29 16:59:20 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dest;
	int		size;

	i = 0;
	if (!s || !f)
		return (0);
	size = ft_strlen(s);
	if (!(dest = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (s[i] != '\0')
	{
		dest[i] = (*f)(s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
