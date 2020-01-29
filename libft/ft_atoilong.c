/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoilong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:32:47 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/14 17:26:01 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoilong(const char *str)
{
	long	result;
	int		i;
	int		j;
	int		flag;

	i = 0;
	result = 0;
	flag = 1;
	while (str[i] == ' ' || (8 < str[i] && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	j = i;
	while (ft_isdigit(str[i]))
		i++;
	while (i > j && ft_isdigit(str[j]))
	{
		result = result * 10 + str[j] - '0';
		j++;
	}
	return (result * flag);
}
