/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:38:13 by sadawi            #+#    #+#             */
/*   Updated: 2019/10/28 13:42:49 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*string(char *s, char c, int index)
{
	int	i;
	int j;
	int strindex;

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
	return (ft_strsub(s, i, j));
}

t_list		*ft_strsplitlst(const char *s, char c)
{
	t_list	*list;
	t_list	*first;
	char	*str;
	int		i;

	i = 0;
	first = NULL;
	while ((str = string((char*)s, c, i)))
	{
		if (!first)
		{
			list = ft_lstnew(str, ft_strlen(str));
			first = list;
		}
		else
		{
			list->next = ft_lstnew(str, ft_strlen(str));
			list = list->next;
		}
		i++;
		ft_strdel(&str);
	}
	return (first);
}
