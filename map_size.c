/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:40:55 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/04 16:58:32 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*size_map_min(int size)
{
	int		map_size;
	char	*map;
	int		i;
	int		j;
	int		k;

	map_size = size * 4;
	k = ft_sqrt(map_size);
	map_size = k * (k + 1);
	if (!(map = (char *)ft_strnew(sizeof(char) * (map_size + 1))))
		return (0);
	i = k;
	j = 0;
	while (j < map_size)
	{
		if (j == i)
		{
			map[j++] = '\n';
			i = i + k;
		}
		map[j++] = '.';
	}
	return (map);
}
