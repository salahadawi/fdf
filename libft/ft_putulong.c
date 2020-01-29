/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:14:45 by sadawi            #+#    #+#             */
/*   Updated: 2019/10/21 17:22:27 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putulong(unsigned long int n)
{
	int i;
	int arr[22];

	i = 0;
	if (n == 0)
		ft_putchar('0');
	while (n)
	{
		arr[i] = n % 10;
		n /= 10;
		i++;
	}
	i--;
	while (i >= 0)
		ft_putchar(arr[i--] + '0');
}
