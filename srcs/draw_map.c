/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:12:27 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/19 16:21:59 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_line(t_line *line, t_mlx *mlx)
{
	int *map;

	if (line->autooffset)
	{
		line->offsetx = 750 - mlx->s_map->cols / 2 * 5 - mlx->s_map->mapxy[0];
		line->offsety = 500 - mlx->s_map->rows / 2 * 5 - mlx->s_map->mapxy[1];
	}
	map = mlx->s_map->mapxy;
	handle_color(line, mlx);
	line->x1 = line->x1 * line->zoom;
	line->x2 = line->x2 * line->zoom;
	line->y1 = line->y1 * line->zoom;
	line->y2 = line->y2 * line->zoom;
	line->z1 = line->z1 * line->zoom * line->pitch;
	line->z2 = line->z2 * line->zoom * line->pitch;
	handle_transform(line);
	line->x1 = line->x1 + line->offsetx;
	line->x2 = line->x2 + line->offsetx;
	line->y1 = line->y1 + line->offsety;
	line->y2 = line->y2 + line->offsety;
	plot_line(line, mlx);
}

void	handle_line_draw(int xy[4], t_line *line, t_mlx *mlx)
{
	int *map;

	map = mlx->s_map->mapxy;
	line->x1 = map[xy[0] * 3 + xy[2] * mlx->s_map->cols * 3];
	line->x2 = map[xy[1] * 3 + xy[3] * mlx->s_map->cols * 3];
	line->y1 = map[xy[2] * mlx->s_map->cols * 3 + xy[0] * 3 + 1];
	line->y2 = map[xy[3] * mlx->s_map->cols * 3 + xy[1] * 3 + 1];
	line->z1 = map[xy[0] * 3 + xy[2] * mlx->s_map->cols * 3 + 2];
	line->z2 = map[xy[1] * 3 + xy[3] * mlx->s_map->cols * 3 + 2];
	draw_line(line, mlx);
}

void	draw_map(t_line *line, t_mlx *mlx)
{
	int y;
	int x;

	y = 0;
	while (y < mlx->s_map->rows)
	{
		x = 0;
		while (x < mlx->s_map->cols)
		{
			if (x + 1 < mlx->s_map->cols)
				handle_line_draw(((int[4]){x, x + 1, y, y}), line, mlx);
			if (y + 1 < mlx->s_map->rows)
				handle_line_draw(((int[4]){x, x, y, y + 1}), line, mlx);
			x++;
		}
		y++;
	}
}

int		handle_drawing(void *param)
{
	t_mlx *mlx;

	mlx = param;
	draw_background(mlx);
	draw_map(mlx->line, mlx);
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->image_ptr, 0, 0);
	if (mlx->gui)
		draw_gui(mlx);
	mlxstr(mlx, 1250, 20, "Press H to toggle GUI");
	return (0);
}
