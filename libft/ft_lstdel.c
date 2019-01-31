/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:28:45 by fgaujard          #+#    #+#             */
/*   Updated: 2018/11/28 15:33:12 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t len))
{
	t_list *next;

	if (!alst || !(*alst) || !del)
		return ;
	while ((*alst)->next != NULL)
	{
		next = (*alst)->next;
		ft_lstdelone(&(*alst), del);
		*alst = next;
	}
	ft_lstdelone(&(*alst), del);
	alst = NULL;
}
