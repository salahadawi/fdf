/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:26:55 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/08 15:57:23 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	handle_hashtag(char **output, char *flag)
{
	char *tmp;

	tmp = *output;
	if (!(*output)[0] || (*output)[0] != '0')
		if (ft_strchr(flag, 'o'))
			*output = ft_strjoin("0", *output);
	if ((*output)[0] != '0')
		handle_hex_precision(output, flag);
	if (ft_strchr(flag, 'f'))
		if (!ft_strchr(*output, '.'))
			*output = ft_strjoin(*output, ".");
	if (!ft_strequ(*output, tmp))
		free(tmp);
}

void	handle_plus(char **output, char *flag)
{
	char *tmp;

	tmp = *output;
	if (ft_strchr(flag, 'd') || ft_strchr(flag, 'i')
		|| ft_strchr(flag, 'f'))
	{
		if ((*output)[0] != '-')
			*output = ft_strjoin("+", *output);
	}
	if (!ft_strequ(*output, tmp))
		free(tmp);
}

void	handle_space(char **output, char *flag)
{
	char *tmp;

	tmp = *output;
	if (ft_strchr(flag, 'd') || ft_strchr(flag, 'i')
		|| ft_strchr(flag, 'f'))
	{
		if ((*output)[0] != '-')
			*output = ft_strjoin(" ", *output);
	}
	if (!ft_strequ(*output, tmp))
		free(tmp);
}

void	handle_hex_precision(char **output, char *flag)
{
	if (ft_strchr(flag, '.'))
	{
		if ((*ft_strchr(flag, '.') + 1 != '0')
			&& ft_isdigit(*ft_strchr(flag, '.') + 1))
		{
			if (ft_strchr(flag, 'x'))
				*output = ft_strjoin("0x", *output);
			else if (ft_strchr(flag, 'X'))
				*output = ft_strjoin("0X", *output);
		}
	}
	else
	{
		if (ft_strchr(flag, 'x'))
			*output = ft_strjoin("0x", *output);
		else if (ft_strchr(flag, 'X'))
			*output = ft_strjoin("0X", *output);
	}
}
