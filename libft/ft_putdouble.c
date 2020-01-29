/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:14:45 by sadawi            #+#    #+#             */
/*   Updated: 2019/11/29 14:08:53 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdouble(long double d, int precision)
{
	ft_putlong((long)d);
	if (precision == 0)
		return ;
	d -= (long)d;
	if (d < 0)
		d *= -1;
	ft_putchar('.');
	while (precision-- >= 0)
	{
		d *= 10;
		if (precision == -1)
			if (((long)d % 10) > 4)
				d += 10;
	}
	d /= 10;
	ft_putlong((long)d);
}
