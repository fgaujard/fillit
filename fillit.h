/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:35:43 by fgaujard          #+#    #+#             */
/*   Updated: 2019/02/28 18:03:19 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*read_file(int fd);
int		main(int ac, char **av);
char	**fill_tetri(char *str);
int		verif_malloced_tetri(char *tetri);

#endif
