/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:13:01 by sadawi            #+#    #+#             */
/*   Updated: 2019/10/24 19:43:51 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*first;

	if (!lst)
		return (NULL);
	first = f(lst);
	tmp = first;
	lst = lst->next;
	while (lst)
	{
		tmp->next = f(lst);
		if (!(tmp->next))
		{
			free(tmp->next);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (first);
}
