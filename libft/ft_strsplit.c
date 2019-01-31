/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:13:01 by fgaujard          #+#    #+#             */
/*   Updated: 2018/11/29 17:15:37 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			word++;
		while ((s[i] != c) && (s[i] != '\0'))
			i++;
	}
	return (word);
}

static char		**ft_malloc_letter(char const *s, char c, char **dest)
{
	int		i;
	int		k;
	int		letter;

	i = 0;
	k = 0;
	letter = 0;
	while ((s[k] != '\0') && (i < ft_count_word(s, c)))
	{
		while ((s[k] == c) && (s[k] != '\0'))
			k++;
		while ((s[k] != c) && (s[k] != '\0'))
		{
			k++;
			letter++;
		}
		if (!(dest[i] = (char *)malloc(sizeof(char) * (letter + 1))))
			return (0);
		letter = 0;
		i++;
	}
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dest;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (0);
	if (!(dest = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1))))
		return (0);
	dest[ft_count_word(s, c)] = 0;
	dest = ft_malloc_letter(s, c, dest);
	while ((s[j] != '\0') && (i < ft_count_word(s, c)))
	{
		while ((s[j] == c) && (s[j] != '\0'))
			j++;
		while ((s[j] != c) && (s[j] != '\0'))
			dest[i][k++] = s[j++];
		dest[i++][k] = '\0';
		k = 0;
	}
	return (dest);
}
