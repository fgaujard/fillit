/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:40:55 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/05 11:48:22 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		size_map_min(int size)
{
	int		map_size;
	int		k;

	k = 2;
	map_size = size * 4;
	while ((k * k) <= map_size)
		k++;
	return (k);
}

char			*map(int size)
{
	int		map_size;
	char	*map;
	int		i;
	int		j;
	int		k;

	k = size_map_min(size);
	map_size = k * (k + 1);
	if (!(map = (char *)ft_strnew(sizeof(char) * (map_size + 1))))
		return (0);
	i = k;
	j = 0;
	while (j < map_size)
	{
		map[j++] = '.';
		if (j == i)
		{
			map[j++] = '\n';
			i = i + (k + 1);
		}
	}
	return (map);
}
