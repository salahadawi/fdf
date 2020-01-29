/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:26:55 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/08 15:56:48 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	handle_width(char **output, char *flag)
{
	int		i;
	int		width;
	char	*padding;
	char	*tmp;

	i = 0;
	width = 0;
	while (ft_strchr("#0-+ ", flag[i]))
		i++;
	if (ft_isdigit(flag[i]))
		width = ft_atoi(flag + i);
	width = handle_char_width(output, flag, width);
	if ((int)ft_strlen(*output) < width)
	{
		padding = ft_strnew(width - ft_strlen(*output));
		ft_memset(padding, ' ', width - ft_strlen(*output));
		tmp = *output;
		if (ft_strchr(flag, '-') && ft_strchr(flag, 'c') && !(*output)[0])
			handle_char_minus(output, padding);
		else if (ft_strchr(flag, '-'))
			*output = ft_strjoin(*output, padding);
		else
			*output = ft_strjoin(padding, *output);
		free_two(&tmp, &padding);
	}
}

void	handle_zero(char **output, char *flag)
{
	int		i;
	int		width;
	char	*padding;
	char	*tmp;

	i = 0;
	width = 0;
	if (ft_strchr(flag, '.') && flag_integer(flag))
		return ;
	while (ft_strchr("#0-+ ", flag[i]))
		i++;
	if (ft_isdigit(flag[i]))
		width = ft_atoi(flag + i);
	width = handle_char_width(output, flag, width);
	if ((int)ft_strlen(*output) < width)
	{
		padding = ft_strnew(width - ft_strlen(*output));
		ft_memset(padding, '0', width - ft_strlen(*output));
		tmp = *output;
		add_width(output, flag, padding);
		free_two(&tmp, &padding);
	}
}

void	handle_precision(char **output, char *flag)
{
	char	*padding;
	char	*tmp;
	int		precision;
	int		len;

	len = ft_strlen(*output);
	if (ft_strchr(flag, 's') || ft_strchr(flag, 'p'))
		if (len > ft_atoi(ft_strchr(flag, '.') + 1))
			(*output)[ft_atoi(ft_strchr(flag, '.') + 1)] = '\0';
	if (!flag_integer(flag))
		return ;
	if ((*output)[0] == '-')
		len--;
	precision = ft_atoi(ft_strchr(flag, '.') + 1);
	if (!precision && !ft_atoi(*output))
		ft_strclr(*output);
	if (len < precision)
	{
		padding = ft_strnew(precision - len);
		ft_memset(padding, '0', precision - len);
		tmp = *output;
		add_width(output, flag, padding);
		free_two(&tmp, &padding);
	}
}

void	add_width(char **output, char *flag, char *padding)
{
	int		i;
	char	*start;
	char	*end;
	char	*tmp;

	i = 0;
	if (!flag_integer(flag))
		*output = ft_strjoin(padding, *output);
	if ((*output)[i] == '+' || (*output)[i] == '-' || (*output)[i] == ' '
		|| (*output)[i] == '0')
		i++;
	if ((*output)[i] == 'x' || (*output)[i] == 'X')
		i++;
	start = ft_strsub(*output, 0, i);
	end = ft_strsub(*output, i, ft_strlen(*output) - i);
	tmp = ft_strjoin(start, padding);
	*output = ft_strjoin(tmp, end);
	free(tmp);
	free_two(&start, &end);
}

void	free_two(char **s1, char **s2)
{
	free(*s1);
	free(*s2);
}
