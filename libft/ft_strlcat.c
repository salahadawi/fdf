/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:33:02 by sadawi            #+#    #+#             */
/*   Updated: 2019/10/23 16:39:21 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(dst);
	if (dstsize == 0 || len > dstsize)
		return (ft_strlen(src) + dstsize);
	while (dst[i])
		i++;
	while (src[j])
	{
		if (i + j < (int)dstsize - 1)
			dst[i + j] = src[j];
		j++;
		if (i + j < (int)dstsize)
			dst[i + j] = '\0';
	}
	return (i + j);
}
