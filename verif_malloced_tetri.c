/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:11:36 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/07 18:29:31 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		verif_endline(char *tetri)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (tetri[4 + (5 * i)] != '\n')
			return (0);
		i++;
	}
	if (tetri[20] != '\0')
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
			if (tetri[i + 1] == '#')
				j++;
			if (tetri[i + 5] == '#')
				j++;
			if (tetri[i - 1] == '#')
				j++;
			if (tetri[i - 5] == '#')
				j++;
			i++;
			ft_putnbr(j);
		}
	}
	ft_putstr("\n");
	ft_putnbr(j);
	if (6 <= j && j <= 8)
		return (1);
	return (0);
}

int				verif_malloced_tetri(char *tetri)
{
	if (verif_endline(tetri) != 1)
	{
		ft_putstr("KOline");
		return (0);
	}
	if (verif_tags(tetri) != 1)
	{
		ft_putstr("KOtags");
		return (0);
	}
	return (1);
}
