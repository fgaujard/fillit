/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_valid_tetri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:07:19 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/07 18:16:46 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**malloc_tetri(int size)
{
	char	**tetri;
	int		i;

	if (!(tetri = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(tetri[i] = (char *)ft_strnew(sizeof(char) * 20)))
			return (NULL);
		i++;
	}
	return (tetri);
}

char			**fill_valid_tetri(char *str, int size)
{
	char	**tetri;
	int		i;
	int		j;
	int		k;

	tetri = malloc_tetri(size);
	i = 0;
	j = 0;
	k = 0;
	while ((i < size) && (str[k] != '\0'))
	{
		while ((j < 19) && (str[k] != '\0'))
			tetri[i][j++] = str[k++];
		k++;
		if (verif_malloced_tetri(tetri[i]) != 1)
			return (NULL);
//		printf("tetri[%i] =\n%s\n\n", i, tetri[i]);
		i++;
		j = 0;
	}
	return (tetri);
}
