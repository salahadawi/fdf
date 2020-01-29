/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:37:22 by sadawi            #+#    #+#             */
/*   Updated: 2019/11/06 13:44:30 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (!(ptr = (unsigned char*)malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i++] = 0;
	}
	return ((void *)ptr);
}
