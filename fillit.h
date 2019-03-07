/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:35:43 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/07 16:57:18 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*read_file(int fd);
int		main(int ac, char **av);
char	**fill_valid_tetri(char *str, int size);
int		verif_malloced_tetri(char *tetri);
int		count_tetri(char *str);
char	**parse_tetri(char **tetri);
char	*ft_map(int nb_t, char **tetri);
int		ft_solver(char **tetri, char *map, int len, int i);
void	ft_fill(char *tetrimino, char *map, int pos, char c);

#endif
