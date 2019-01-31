/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:14:46 by fgaujard          #+#    #+#             */
/*   Updated: 2018/11/30 16:52:05 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*dest;

	i = 0;
	if (!s)
		return (0);
	j = (ft_strlen(s) - 1);
	while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' ') && (s[i] != '\0'))
		i++;
	while ((s[j] == '\t' || s[j] == '\n' || s[j] == ' ') && (j > i))
		j--;
	if (!(dest = (char *)malloc(sizeof(char) * (j - i + 1))))
		return (0);
	k = 0;
	while (i <= j)
		dest[k++] = s[i++];
	dest[k] = '\0';
	return (dest);
}
