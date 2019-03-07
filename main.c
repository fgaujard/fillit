/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:31:50 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/07 18:12:25 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		print_error(void)
{
	ft_putendl("error");
	exit(1);
}

static void		do_it_and_clear(char *str, char **tetri, int size)
{
	char	*map;

	tetri = parse_tetri(tetri);
	map = ft_map(size, tetri);
	ft_putendl(map);
	ft_strdel(&str);
	ft_free_tables(tetri);
	ft_strdel(&map);
}

int				main(int ac, char **av)
{
	int		fd;
	char	*str;
	char	**tetri;
	int		size;

	if (ac != 2)
		print_error();
	fd = open(av[1], O_RDONLY);
	str = read_file(fd);
	if (!str)
		print_error();
	printf("%s\n", str);
	size = count_tetri(str);
	if (size == 0)
		print_error();
	printf("%i", size);
	tetri = fill_valid_tetri(str, size);
	if (!tetri)
		print_error();
	do_it_and_clear(str, tetri, size);
	close(fd);
	return (0);
}
