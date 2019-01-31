/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:03:09 by fgaujard          #+#    #+#             */
/*   Updated: 2018/11/29 17:17:13 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*s3;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	size = (ft_strlen(s1) + ft_strlen(s2));
	if (!(s3 = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		s3[j++] = s2[i++];
	s3[j] = '\0';
	return (s3);
}
