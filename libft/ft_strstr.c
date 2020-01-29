/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:53:01 by sadawi            #+#    #+#             */
/*   Updated: 2019/10/28 19:32:07 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j])
		{
			if (!needle[j + 1])
				return ((char*)&haystack[i]);
			j++;
		}
		i++;
		j = 0;
	}
	return (NULL);
}
