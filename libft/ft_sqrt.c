/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:08:43 by fgaujard          #+#    #+#             */
/*   Updated: 2019/03/04 16:11:30 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb == 1)
		return (1);
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}
