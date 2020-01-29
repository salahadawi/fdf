/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:54:55 by sadawi            #+#    #+#             */
/*   Updated: 2019/12/11 13:14:02 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nbrlen_base(long n, int base)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	while (n || i == 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

static char	base_digit(long n, int base)
{
	char	*format;
	int		i;

	format = "0123456789ABCDEF";
	i = n % base;
	if (i < 0)
		i *= -1;
	return (format[i]);
}

char		*ft_itoa_base(long n, int base)
{
	int		i;
	char	*arr;

	if (base < 2 || 16 < base)
		return (NULL);
	i = ft_nbrlen_base(n, base);
	if (!(arr = ft_strnew(i)))
		return (NULL);
	if (n < 0)
	{
		arr[0] = '-';
	}
	arr[i--] = '\0';
	while (i >= 0 && arr[i] != '-')
	{
		arr[i--] = base_digit(n, base);
		n /= base;
	}
	return (arr);
}
