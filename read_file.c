/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:44:14 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/06 18:21:51 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*static int		verif_size(char *file)
{
	int len;

	len = ft_strlen(file);
	printf("%i\n", len);
	return (0);
}*/

char			*read_file(int fd)
{
	char	str[22];
	char	*file;
	int		nb_car_read;

	file = NULL;
	ft_bzero(str, 22);
	while ((nb_car_read = read(fd, str, 21)) > 0)
	{
		if (nb_car_read < 21)
		{
			if (str[19] == '\n' && str[20] != '\n')
				ft_putstr("ok\n");
			else
				ft_putstr("error\n");
		}
		file = ft_strappend(file, str);
	}
	return (file);
}
