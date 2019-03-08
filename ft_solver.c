/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behiraux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:09:48 by behiraux          #+#    #+#             */
/*   Updated: 2019/03/07 15:28:00 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_isok(char *tetrimino, char *map, int pos, char c)
{
	int i;
	int x;
	int begin;
	int map_size;

	i = 0;
	x = ft_idxof(tetrimino, '\n') - 1;
	begin = pos;
	map_size = ft_idxof(map, '\n');
	while (tetrimino[i] != '\0')
	{
		if (tetrimino[i] == '.')
			pos++;
		else if (tetrimino[i] == '#')
		{
			if (map[pos] != '.')
				return (0);
			pos++;
		}
		else if (tetrimino[i] == '\n')
			pos = pos + map_size - x;
		i++;
	}
	ft_fill(tetrimino, map, begin, c);
	return (1);
}

void		ft_fill(char *tetrimino, char *map, int pos, char c)
{
	int	i;
	int	x;
	int	map_size;

	i = 0;
	x = ft_idxof(tetrimino, '\n') - 1;
	map_size = ft_idxof(map, '\n');
	while (tetrimino[i] != '\0')
	{
		if (tetrimino[i] == '.')
			pos++;
		else if (tetrimino[i] == '#')
			map[pos++] = c;
		else if (tetrimino[i] == '\n')
			pos = pos + map_size - x;
		i++;
	}
}

static void	ft_remove(char *map, char c)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == c)
			map[i] = '.';
		i++;
	}
}

int			ft_solver(char **tetri, char *map, int len, int i)
{
	int		pos;
	int		x;
	int		y;

	pos = -1;
	x = 1;
	y = 1;
	while (map[y] != '\n' && pos != len)
	{
		if ((ft_isok(tetri[i], map, ++pos, 'A' + i)) == 1)
		{
			if (tetri[i + 1] == NULL || ft_solver(tetri, map, len, i + 1) != 0)
				return (1);
			else
				ft_remove(map, 'A' + i);
		}
		if (map[x] == '\n')
		{
			y++;
			x = 0;
		}
	}
	return (0);
}
