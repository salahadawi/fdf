/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:01:26 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/19 16:21:50 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_color_high(t_line *line, double d)
{
	if (d < 0.125)
		line->color = 0x40e191;
	else if (d < 0.25)
		line->color = 0x00c3a0;
	else if (d < 0.375)
		line->color = 0x00a5af;
	else if (d < 0.5)
		line->color = 0x0087be;
	else if (d < 0.625)
		line->color = 0x0069cd;
	else if (d < 0.75)
		line->color = 0x004bdc;
	else if (d < 0.875)
		line->color = 0x002deb;
	else if (d <= 1)
		line->color = 0x0000ff;
}

void	handle_color_low(t_line *line, double d)
{
	if (d > -0.125)
		line->color = 0x91e140;
	else if (d > -0.25)
		line->color = 0xa0c300;
	else if (d > -0.375)
		line->color = 0xafa500;
	else if (d > -0.5)
		line->color = 0xbe8700;
	else if (d > -0.625)
		line->color = 0xcd6900;
	else if (d > -0.75)
		line->color = 0xdc4b00;
	else if (d > -0.875)
		line->color = 0xeb2d00;
	else if (d >= -1)
		line->color = 0xff0000;
}

void	handle_simple_color(t_line *line)
{
	if (line->z1 && line->z2)
	{
		if (line->z1 + line->z2 > 0)
			line->color = 0x0000FF;
		else
			line->color = 0xFF0000;
	}
	else if (line->z1 || line->z2)
	{
		if (line->z1 > 0 || line->z2 > 0)
			line->color = 0x0000FF;
		else
			line->color = 0xFF0000;
	}
	else
		line->color = 0xFFFFFF;
}

void	handle_color(t_line *line, t_mlx *mlx)
{
	double d;

	if (!line->colors)
	{
		handle_simple_color(line);
		return ;
	}
	d = (line->z1 + line->z2) / 2;
	d /= mlx->s_map->biggestz;
	if (d > 0)
		handle_color_high(line, d);
	else if (d < 0)
		handle_color_low(line, d);
	else
		line->color = 0xa4ffa4;
}
