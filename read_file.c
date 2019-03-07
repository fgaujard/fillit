/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:44:14 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/07 18:20:03 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*read_file(int fd)
{
	char	str[21];
	char	*file;
	int		nb_car_read;

	file = NULL;
	ft_bzero(str, 21);
	while ((nb_car_read = read(fd, str, 20)) > 0)
	{
		if (nb_car_read != 20)
			return (NULL);
		file = ft_strappend(file, str);
		ft_bzero(str, 21);
		nb_car_read = read(fd, str, 1);
		if (str[0] == '\0')
			return (file);
	}
	return (file);
}
