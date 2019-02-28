/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_malloced_tetri.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:37:26 by fgaujard          #+#    #+#             */
/*   Updated: 2019/02/28 16:51:28 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		count_block(char *tetri)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetri[i] != '\0')
	{
		if ((tetri[i] != '.') || (tetri[i] != '#') || (tetri[i] != '\n'))
			return (0);
		if (tetri[i] == '#')
			j++;
	i++;
	}
	if (j == 4)
		return (1);
	return (0);
}

static int		verif_forms(char *tetri)
{
	int i;

	i = 0;
	while (tetri[i] != '\0')
	{
		while (tetri[i] == '.')
			i++;
		if (tetri[i] == '#')
		{
			if (tetri[i + 5] == '#')
			{
				if (tetri[i + 4] == '#')
					if (tetri[i + 3] == '#' || tetri[i + 10] == '#')
						return (1);
				if (tetri[i + 10] == '#')
					if (tetri[i + 9] == '#' || tetri[i + 15] == '#' || tetri[i + 11] == '#')
						return (1);
				if (tetri[i + 6] == '#')
					if (tetri[i + 7] == '#' || tetri[i + 11] == '#')
						return (1);
			}
			if (tetri[i + 1] == '#')
			{
				if (tetri[i + 6] == '#')
					if (tetri[i + 5] == '#' || tetri[i + 11] == '#' || tetri[i + 7] == '#')
						return (1);
				if (tetri[i + 2] == '#')
					if (tetri[i + 7] == '#' || tetri[i + 3] == '#')
						return (1);
			}
		}
	}
	return (0);
}

int				verif_malloced_tetri(char *tetri)
{
	if (count_block(tetri) != 1)
		return (0);
	if (verif_forms(tetri) != 1)
		return (0);
	return (1);
}
