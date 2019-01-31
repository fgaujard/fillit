/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:52:36 by fgaujard          #+#    #+#             */
/*   Updated: 2019/01/22 12:23:05 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *s1, char *s2)
{
	char	*s3;
	int		size;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	if (!s1 && !s2)
		return (0);
	size = (ft_strlen(s1) + ft_strlen(s2));
	if (!(s3 = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		s3[j++] = s1[i++];
	i = 0;
	free(s1);
	while (s2[i] != '\0')
		s3[j++] = s2[i++];
	s3[j] = '\0';
	return (s3);
}
