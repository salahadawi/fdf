/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:16:28 by sadawi            #+#    #+#             */
/*   Updated: 2019/10/24 13:36:35 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *link;

	if (!(link = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	link->next = NULL;
	if (!(content))
	{
		link->content = NULL;
		link->content_size = 0;
		return (link);
	}
	if (!(link->content = ft_memalloc(content_size)))
	{
		free(link);
		return (NULL);
	}
	ft_memcpy(link->content, content, content_size);
	link->content_size = content_size;
	return (link);
}
