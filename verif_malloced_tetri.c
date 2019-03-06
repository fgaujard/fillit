/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:11:36 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/06 18:27:35 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		verif_endline(char *tetri)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tetri[4 + (5 * i)] != '\n')
			return (0);
		i++;
	}
	if (tetri[20] != '\n')
		return (0);
	return (1);
}

static int		verif_tags(char *tetri)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetri[i] != '\0')
	{
		while (tetri[i] == '.' || tetri[i] == '\n')
			i++;
		if (tetri[i] == '#')
		{
			if (tetri[i + 1] == '#' || tetri[i + 5] == '#' \
				|| tetri[i - 1] == '#' || tetri[i - 5] == '#')
				j++;
			i++;
		}
	}
	if (j == 4)
		return (1);
	return (0);
}

int				verif_malloced_tetri(char *tetri)
{
	if (verif_endline(tetri) != 1)
		return (0);
	if (verif_tags(tetri) != 1)
		return (0);
	return (1);
}
