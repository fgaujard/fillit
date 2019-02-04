/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:44:14 by fgaujard          #+#    #+#             */
/*   Updated: 2019/02/04 16:55:27 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <fcntl.h>

char	*read_file(int fd)
{
	char str[22];
	char *file;

	if ((!file && (file = (char *)ft_strnew(sizeof(*file))) == NULL))
		return (0);
	while (read(fd, str, 21) > 0)
	{
		str[21] = '\0';
		file = ft_strjoin(file, str);
	}
	return (file);
}

int		main(int ac, char **av)
{
	int fd;

	if (ac != 2)
	{
		write(2, "error\n", 6);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	ft_putstr(read_file(fd));
	close(fd);
	return (0);
}
