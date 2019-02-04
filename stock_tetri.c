/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:56:23 by fgaujard          #+#    #+#             */
/*   Updated: 2019/02/04 16:48:48 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		count_tetri(char *str)
{
	int i;
	int j;
	
	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == '\n')
			if (str[++i] == '\n')
				j++;
	}
	return (j);
}

static int		malloc_tetri(char *str)
{
	int i;
	char **tetri;

	i = 0;
	if (!(tetri = (char *)malloc(sizeof(char) * (count_tetri + 1))))
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			if (str[++i] == '\n')
	}
}
