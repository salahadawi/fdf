/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:26:55 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/08 15:57:34 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	handle_char_minus(char **output, char *padding)
{
	*output = ft_strjoin("a", padding);
	(*output)[0] = '\0';
}

int		handle_char_width(char **output, char *flag, int width)
{
	if (ft_strchr(flag, 'c'))
		if (!(**output) && width > 1)
			return (--width);
	return (width);
}

int		handle_char_output(char **output, char *flag)
{
	int width;
	int i;

	i = 0;
	width = 1;
	while (ft_strchr("#0-+ ", flag[i]))
		i++;
	if (ft_isdigit(flag[i]))
		width = ft_atoi(flag + i);
	i = 0;
	while (width > i)
		ft_putchar((*output)[i++]);
	return (width);
}
