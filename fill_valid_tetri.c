/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_valid_tetri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:12:08 by fgaujard          #+#    #+#             */
/*   Updated: 2019/02/28 16:54:29 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		count_tetri(char *str)
{
	int len;
	int size;

	len = ft_strlen(str);
	if (len % 21 != 0)
		return (0);
	size = len / 21;
	printf("len : %d\nsize : %d\n", len, size);
	return (size);
}

static char		**malloc_tetri(int size)
{
	char	**tetri;
	int		i;

	if (!(tetri = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(tetri[i] = (char *)ft_strnew(sizeof(char) * 21)))
			return (NULL);
		i++;
	}
	return (tetri);
}

char	**fill_tetri(char *str)
{
	char	**tetri;
	int		size;
	int		i;
	int		j;
	int		k;

	size = count_tetri(str);
	tetri = malloc_tetri(size);
	i = 0;
	j = 0;
	k = 0;
	while ((i < size) && (str[k] != '\0'))
	{
		while ((j < 21) && (str[k] != '\0'))
			tetri[i][j++] = str[k++];
		printf("tetri[%i] =\n%s", i, tetri[i]);
		if (verif_malloced_tetri(tetri[i]) != 1)
			printf("KO\n");
		else
			printf("GOOD\n");
		i++;
		j = 0;
	}
	return (tetri);
}
