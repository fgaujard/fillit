/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:41:43 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/06 18:05:55 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_tetri(char *str)
{
	int len;
	int size;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
	{
		if (str[len] != '#' && str[len] != '.' && str[len] != '\n')
			return (0);
		len++;
	}
	if (len % 21 != 0)
		return (0);
	size = len / 21;
	printf("len : %d\nsize : %d\n", len, size);
	return (size);
}
