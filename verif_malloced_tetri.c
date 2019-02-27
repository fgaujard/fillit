/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_malloced_tetri.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:37:26 by fgaujard          #+#    #+#             */
/*   Updated: 2019/02/27 15:21:55 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		count_block(char *tetri)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetri[i] != '\0')
	{
		if ((tetri[i] != '.') || (tetri[i] != '#'))
			return (0);
		if (tetri[i] == '#')
			j++;
	i++;
	}
	if (j > 4)
		j = 1;
	return (j);
}

static int		verif_forms(char *tetri)
{
	int i;

	i = 0;
	while (tetri[i] != '\0')
	{
		while (tetri[i] == '.')
			i++;
		if (tetri[i] == '#')
		{
			if (tetri[i + 1] == '#')
			{
				if (tetri[i + 2] == '#')
				{
					if (tetri[i + 3] == '#')
						return (1);
			else if (tetri [i + 5] == '#')
			{
				if (tetri[i + 10] == '#')
				{
					if (tetri[i + 15] == '#')
						return (1);
				}
				else if (tetri[i + 4] == '#')
				{
					if (tetri[i + 9] == '#')
						return (1);
			}
}
