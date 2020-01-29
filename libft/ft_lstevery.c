/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstevery.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:35:08 by sadawi            #+#    #+#             */
/*   Updated: 2019/10/28 13:43:11 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstevery(t_list *lst, int (*f)(t_list *elem))
{
	while (lst)
	{
		if (!f(lst))
			return (0);
		lst = lst->next;
	}
	return (1);
}
