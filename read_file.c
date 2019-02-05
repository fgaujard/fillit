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

#include "fillit.h"

char	*read_file(int fd)
{
	char str[22];
	char *file;

	file = NULL;
	while (read(fd, str, 21) > 0)
	{
		str[21] = '\0';
		file = ft_strappend(file, str);
	}
	return (file);
}
