/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:23:28 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/06 17:57:23 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_len(int fd)
{
	char c;
	int len;

	len = 0;
	c = '\0';
	while (read(fd, &c, 1) > 0)
		len++;
	printf("%i", len);
	if (((len + 1) % 21) != 0)
		return (0);
	return (len + 1);
}

char			*read_file(int fd)
{
	int len;
	int i;
	char c;
	char *str;

	len = check_len(fd);
	if (!(str = (char *)ft_strnew(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	c = '\0';
	while ((read(fd, &c, 1) > 0) && (i < len))
		str[i++] = c;
	str[i] = '\0';
	printf("%s", str);
	return (str);
}
