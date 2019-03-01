/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:11:36 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/01 14:43:03 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		verif_malloced_tetri(char *tetri)
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
			i++;
		}
		printf("pos[%i]\nnbj=%i\n", i-1,j);
	}
	if (j == 4)
		return (1);
	return (0);
}
