/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:41:43 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/04 15:45:06 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_tetri(char *str)
{
	int len;
	int size;

	len = ft_strlen(str);
	if (len % 21 != '\0')
		return (0);
	size = len / 21;
//	printf("len : %d\nsize : %d\n, len, size);
	return (size);
}
