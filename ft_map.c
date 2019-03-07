/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:37:50 by behiraux          #+#    #+#             */
/*   Updated: 2019/03/04 14:42:07 by behiraux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_sqrtmap(int x)
{
	int i;

	i = 2;
	while (i * i < x)
		i++;
	return (i);
}

static char	*ft_map_size(int x)
{
	int		i;
	int		p;
	int		size;
	char	*map;

	size = x * x + x;
	i = 0;
	p = 1;
	if (!(map = (char *)ft_memalloc(sizeof(char) * (size))))
		return (NULL);
	while (i < size - 1)
	{
		if (p % (x + 1) == 0)
			map[i] = '\n';
		else
			map[i] = '.';
		i++;
		p++;
	}
	map[i] = '\0';
	return (map);
}

char		*ft_map(int nb_t, char **tetri)
{
	int		x;
	int		size;
	int		i;
	char	*map;
	int		len;

	size = nb_t * 4;
	x = ft_sqrtmap(size);
	i = 0;
	if ((map = ft_map_size(x)) == NULL)
		return (NULL);
	len = ft_strlen(map);
	while (ft_solver(tetri, map, len, 0) == 0)
	{
		free(map);
		x++;
		map = ft_map_size(x);
		len = ft_strlen(map);
	}
	return (map);
}
