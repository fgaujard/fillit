/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:11:36 by fgaujard          #+#    #+#             */
/*   Updated: 2019/02/28 17:31:52 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		verif_malloced_tetri(char *tetri)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 100;
	while (tetri[i] != '\0')
	{
		while (tetri[i] == '.' || tetri[i] == '\n')
			i++;
		if ((tetri[i] == '#') && (i != k))
		{
			if (tetri[i - 1] == '#')
			{
				j++;
				k = i - 1;
				i++;
			}
			if (tetri[i + 1] == '#')
			{
				j++;
				k = i + 1;
				i++;
			}
			if (tetri[i + 5] == '#')
			{
				j++;
				k = i + 5;
				i++;
			}
		}
		else 
		{
			i++;
			k = 100;
		}
		printf("%i", j);
	}
	if (j == 4)
		return (1);
	return (0);
}
