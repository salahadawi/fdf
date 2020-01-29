/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:26:55 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/08 15:56:39 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		amount;

	amount = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			amount += handle_flags(&format, &args);
		else
			ft_putchar(*format);
		format++;
		amount++;
	}
	return (amount);
}

char	*toaddress(unsigned long n)
{
	char *address;
	char *tmp;

	address = (char*)malloc(15);
	ft_strcpy(address, "0x");
	tmp = ft_itoa_base_ul_low(n, 16);
	ft_strcat(address, tmp);
	free(tmp);
	return (address);
}

int		handle_output(char **output, char *flag)
{
	int len;

	handle_flag(output, flag);
	if (ft_strchr(flag, 'c'))
		len = handle_char_output(output, flag);
	else
	{
		ft_putstr(*output);
		len = ft_strlen(*output);
	}
	free(*output);
	return (len);
}
