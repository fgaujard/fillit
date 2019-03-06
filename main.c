/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:31:50 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/06 18:06:56 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*str;
	char	**tetri;
	int		size;

	if (ac != 2)
	{
		write(2, "error\n", 6);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	str = read_file(fd);
	ft_putstr(str);
	size = count_tetri(str);
	tetri = fill_valid_tetri(str, size);
	tetri = parse_tetri(tetri);
	//ft_putstr(map(size));
	ft_strdel(&str);
	ft_free_tables(tetri);
	close(fd);
	return (0);
}
