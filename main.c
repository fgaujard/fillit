/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:31:50 by fgaujard          #+#    #+#             */
/*   Updated: 2019/02/07 17:24:56 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*str;

	if (ac != 2)
	{
		write(2, "error\n", 6);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	str = read_file(fd);
	ft_putstr(str);
	fill_tetri(str);
	close(fd);
	return(0);
}
