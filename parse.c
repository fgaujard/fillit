/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:03:40 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/07 18:23:39 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		kill_dot_column(char *tetri)
{
	int i;

	i = 0;
	while (tetri[i] != '\n' && i < 21)
	{
		if (tetri[i] == '#' || tetri[i + 5] == '#' || tetri[i + 10] == '#' \
				|| tetri[i + 15] == '#')
			i++;
		else
		{
			tetri[i] = '!';
			tetri[i + 5] = '!';
			tetri[i + 10] = '!';
			tetri[i + 15] = '!';
			i++;
		}
	}
}

static void		kill_dot_line(char *tetri)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (tetri[i] == '#' || tetri[i + 1] == '#' || tetri[i + 2] == '#' \
				|| tetri[i + 3] == '#')
			i = i + 5;
		else
		{
			tetri[i] = '!';
			tetri[i + 1] = '!';
			tetri[i + 2] = '!';
			tetri[i + 3] = '!';
			if (tetri[i + 4] != '\0')
				tetri[i + 4] = '!';
			i = i + 5;
		}
	}
}

static	void	extract_tetri(char *tetri, char *parsed)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (tetri[i] != '\0' && k < 4)
	{
		if (tetri[i] == '!')
			i++;
		if (tetri[i] != '!' && tetri[i] != '\0')
		{
			if (tetri[i] == '#')
				k++;
			parsed[j++] = tetri[i++];
		}
	}
	if (parsed[j - 1] != '#' && parsed[j - 1] != '.')
		parsed[--j] = '\0';
}

char			**parse_tetri(char **tetri)
{
	int		i;
	char	*parsed;

	i = 0;
	while (tetri[i] != 0)
	{
		if (!(parsed = (char *)ft_strnew(sizeof(char) * 8)))
			return (0);
		kill_dot_column(tetri[i]);
		kill_dot_line(tetri[i]);
		extract_tetri(tetri[i], parsed);
		ft_bzero(tetri[i], 21);
		ft_strcpy(tetri[i], parsed);
		free(parsed);
		i++;
	}
	return (tetri);
}
