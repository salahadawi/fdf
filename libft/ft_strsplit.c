/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:38:13 by sadawi            #+#    #+#             */
/*   Updated: 2019/10/24 13:37:46 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	count_strings(char *str, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[j] == c)
		j++;
	if (str[j] == '\0')
		return (0);
	while (str[j + 1])
	{
		if (str[j] == c && str[j + 1] != c)
			i++;
		j++;
	}
	return (i + 1);
}

static char	*string(char *s, char c, int index)
{
	int		i;
	int		j;
	int		strindex;
	char	*str;

	i = 0;
	j = 0;
	strindex = 0;
	while (s[i] == c)
		i++;
	while (strindex < index)
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c)
			i++;
		strindex++;
	}
	if (!(s[i]))
		return (NULL);
	while (s[i + j] != c && s[i + j] != '\0')
		j++;
	return (str = ft_strsub(s, i, j));
}

char		**ft_strsplit(const char *s, char c)
{
	char	**arr;
	int		i;

	i = 0;
	if (!(arr = (char**)malloc(sizeof(arr) * count_strings((char*)s, c) + 1)))
		return (NULL);
	while ((arr[i] = string((char*)s, c, i)))
		i++;
	arr[i] = 0;
	return (arr);
}
