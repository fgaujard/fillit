/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaujard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:29:01 by fgaujard          #+#    #+#             */
/*   Updated: 2018/11/30 18:49:43 by fgaujard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	new->content_size = content_size;
	new->next = NULL;
	if (content)
	{
		if (!(new->content = malloc(content_size)))
			return (NULL);
		new->content = ft_memmove(new->content, content, content_size);
	}
	else
	{
		new->content_size = 0;
		new->content = NULL;
	}
	return (new);
}
