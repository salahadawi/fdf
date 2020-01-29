/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_digit_datatypes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:26:55 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/08 15:56:57 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	handle_signed(char *flag, va_list *args)
{
	char	*output;
	long	tmp;

	if (ft_strchr(flag, 'c'))
		output = ft_chartostr(va_arg(*args, int));
	else if (ft_strstr(flag, "hhi") || ft_strstr(flag, "hhd"))
		tmp = (signed char)va_arg(*args, int);
	else if (ft_strstr(flag, "hi") || ft_strstr(flag, "hd"))
		tmp = (short)va_arg(*args, int);
	else if (ft_strstr(flag, "lli") || ft_strstr(flag, "lld"))
		tmp = (long)va_arg(*args, long);
	else if (ft_strstr(flag, "li") || ft_strstr(flag, "ld"))
		tmp = (long)va_arg(*args, long);
	else if (ft_strchr(flag, 'd') || ft_strchr(flag, 'i'))
		tmp = va_arg(*args, int);
	else
		return (0);
	if (!ft_strchr(flag, 'c'))
		output = ft_itoa_base(tmp, 10);
	return (handle_output(&output, flag));
}

int	handle_unsigned(char *flag, va_list *args)
{
	char			*output;
	unsigned long	tmp;

	if (ft_strstr(flag, "hhu"))
		tmp = (unsigned char)va_arg(*args, unsigned int);
	else if (ft_strstr(flag, "hu"))
		tmp = (unsigned short)va_arg(*args, unsigned int);
	else if (ft_strstr(flag, "llu") || ft_strstr(flag, "lu"))
		tmp = (unsigned long)va_arg(*args, unsigned long);
	else if (ft_strchr(flag, 'u'))
		tmp = (unsigned int)va_arg(*args, unsigned int);
	else
		return (0);
	output = ft_itoa_base_ul(tmp, 10);
	return (handle_output(&output, flag));
}

int	handle_float(char *flag, va_list *args)
{
	char		*output;
	long double tmp;
	int			precision;

	if (ft_strchr(flag, '.'))
		precision = ft_atoi(ft_strchr(flag, '.') + 1);
	else
		precision = 6;
	if (ft_strstr(flag, "Lf"))
		tmp = va_arg(*args, long double);
	else if (ft_strchr(flag, 'f'))
		tmp = va_arg(*args, double);
	else
		return (0);
	output = ft_itoa_double(tmp, precision);
	return (handle_output(&output, flag));
}
