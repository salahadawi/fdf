/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string_datatypes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:26:55 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/08 15:57:04 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	handle_base(char *flag, va_list *args)
{
	char			*output;
	unsigned long	tmp;

	if (check_flag_thrice(flag, "llx", "llX", "llo"))
		tmp = (unsigned long)va_arg(*args, unsigned long);
	else if (check_flag_thrice(flag, "lx", "lX", "lo"))
		tmp = (unsigned long)va_arg(*args, unsigned long);
	else if (check_flag_thrice(flag, "hhx", "hhX", "hho"))
		tmp = (unsigned char)va_arg(*args, unsigned int);
	else if (check_flag_thrice(flag, "hx", "hX", "ho"))
		tmp = (unsigned short)va_arg(*args, unsigned int);
	else if (check_flag_thrice(flag, "x", "X", "o"))
		tmp = va_arg(*args, unsigned int);
	else
		return (0);
	if (ft_strchr(flag, 'x'))
		output = ft_itoa_base_ul_low(tmp, 16);
	else if (ft_strchr(flag, 'X'))
		output = ft_itoa_base_ul(tmp, 16);
	else
		output = ft_itoa_base_ul_low(tmp, 8);
	return (handle_output(&output, flag));
}

int	handle_pointer(char *flag, va_list *args)
{
	char			*output;
	unsigned long	tmp;

	if (ft_strchr(flag, 's'))
	{
		output = ft_strdup(va_arg(*args, char*));
		if (!output)
			output = ft_strdup("(null)");
	}
	else if (ft_strchr(flag, 'p'))
	{
		tmp = va_arg(*args, unsigned long);
		output = toaddress(tmp);
	}
	else
		return (0);
	return (handle_output(&output, flag));
}

int	handle_percent(char *flag)
{
	char	*output;

	if (ft_strchr(flag, '%'))
		output = ft_strdup("%");
	else
		return (0);
	return (handle_output(&output, flag));
}

int	check_flag_thrice(char *flag, char *s1, char *s2, char *s3)
{
	return (ft_strstr(flag, s1) || ft_strstr(flag, s2) || ft_strstr(flag, s3));
}
