/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:11:53 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/19 16:23:28 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_pixel(int x, int y, int color, t_mlx *mlx)
{
	int r;
	int g;
	int b;

	if (x <= 0 || y <= 0 || WIN_WIDTH <= x || WIN_HEIGHT <= y)
		return ;
	b = color % 256;
	g = color / 256 % 256;
	r = color / 256 / 256 % 256;
	mlx->image[x * 4 + y * mlx->size_line] = r;
	mlx->image[x * 4 + y * mlx->size_line + 1] = g;
	mlx->image[x * 4 + y * mlx->size_line + 2] = b;
}

void	plot_line_low(t_line *line, t_mlx *mlx)
{
	int *dxy;
	int *xy;
	int yi;
	int d;

	dxy = (int[2]){line->x2 - line->x1, line->y2 - line->y1};
	yi = 1;
	if (dxy[1] < 0)
	{
		yi = -1;
		dxy[1] *= -1;
	}
	d = 2 * dxy[1] - dxy[0];
	xy = (int[2]){line->x1, line->y1};
	while (xy[0] <= line->x2)
	{
		draw_pixel(xy[0], xy[1], line->color, mlx);
		if (d > 0)
		{
			xy[1] += yi;
			d -= 2 * dxy[0];
		}
		xy[0]++;
		d += 2 * dxy[1];
	}
}

void	plot_line_high(t_line *line, t_mlx *mlx)
{
	int *dxy;
	int *xy;
	int xi;
	int d;

	dxy = (int[2]){line->x2 - line->x1, line->y2 - line->y1};
	xi = 1;
	if (dxy[0] < 0)
	{
		xi = -1;
		dxy[0] *= -1;
	}
	d = 2 * dxy[0] - dxy[1];
	xy = (int[2]){line->x1, line->y1};
	while (xy[1] <= line->y2)
	{
		draw_pixel(xy[0], xy[1], line->color, mlx);
		if (d > 0)
		{
			xy[0] += xi;
			d -= 2 * dxy[1];
		}
		xy[1]++;
		d += 2 * dxy[0];
	}
}

void	swap_points(t_line *line)
{
	int tmp;

	tmp = line->x1;
	line->x1 = line->x2;
	line->x2 = tmp;
	tmp = line->y1;
	line->y1 = line->y2;
	line->y2 = tmp;
}

void	plot_line(t_line *line, t_mlx *mlx)
{
	if (abs(line->y2 - line->y1) < abs(line->x2 - line->x1))
	{
		if (line->x1 > line->x2)
			swap_points(line);
		plot_line_low(line, mlx);
	}
	else
	{
		if (line->y1 > line->y2)
			swap_points(line);
		plot_line_high(line, mlx);
	}
}
