/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:31:41 by sadawi            #+#    #+#             */
/*   Updated: 2019/10/25 14:07:16 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	ft_nbrlen(int nbr)
{
	int i;

	i = 0;
	if (nbr < 0)
		i++;
	while (nbr || i == 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*arr;

	i = ft_nbrlen(n);
	if (!(arr = (char *)malloc(i + 1)))
		return (NULL);
	if (n < 0)
	{
		arr[0] = '-';
		if (n == -2147483648)
		{
			arr[1] = (char)(2 + '0');
			n = -147483648;
		}
		n *= -1;
	}
	arr[i--] = '\0';
	while (i >= 0 && arr[i] != '2' && arr[i] != '-')
	{
		arr[i--] = (char)(n % 10 + '0');
		n /= 10;
	}
	return (arr);
}
