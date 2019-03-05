/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:28:22 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/05 18:26:24 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		kill_dot_line(char *tetri)
{
	int i;

	i = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] != '#' || tetri[i + 1] != '#' || tetri[i + 2] != '#' \
				|| tetri[i + 3] != '#')
		{
			while (tetri[i] != '\n')
				tetri[i++] = '@';
			tetri[i] = '@';
		}
		else
		{
			i = i + 4;
		}
		i++;
	}
}

static void		kill_dot_column(char *tetri)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tetri[i] == '#' || tetri[i + 5] == '#' || tetri[i + 10] == '#' \
				|| tetri[i + 15] == '#')
			i++;
		else
		{
			tetri[i] = '@';
			tetri[i + 5] = '@';
			tetri[i + 10] = '@';
			tetri[i + 15] = '@';
			i++;
		}
	}
}

static char		*extract(char *tetri)
{
	int i;
	int j;
	char *parsed;

	i = 0;
	j = 0;
	if (!(parsed = (char *)ft_strnew(sizeof(char) * 8)))
		return (0);
	while (tetri[i] != '\0')
	{
		if (tetri[i] == '@')
			i++;
		if (tetri[i] != '@' && tetri[i] != '\0')
			parsed[j++] = tetri[i++];
	}
	parsed[j--] = '\0';
	return (parsed);
}

char	**parse_tetri(char **tetri)
{
	int i;

	i = 0;
	while (tetri[i] != 0)
	{
		kill_dot_column(tetri[i]);
		printf("%s", tetri[i]);
		kill_dot_line(tetri[i]);
		printf("%s", tetri[i]);
		tetri[i] = extract(tetri[i]);
		printf("%s", tetri[i]);
		i++;
	}
	return (tetri);
}
