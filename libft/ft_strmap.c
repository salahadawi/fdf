/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:55:18 by sadawi            #+#    #+#             */
/*   Updated: 2019/10/25 14:09:51 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (*s)
	{
		str[i] = (*f)(*s++);
		i++;
	}
	str[i] = '\0';
	return (str);
}
