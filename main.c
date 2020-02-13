/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:42 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/13 17:53:57 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		handle_idle(void *param)
{
	(void)param;
	t_mlx *mlx;

	mlx = param;
	if (mlx->line->idle)
		mlx->line->rotatey -= 0.01;
	ft_memset(mlx->image, 0, WINDOW_HEIGHT * WINDOW_WIDTH * 4);
	handle_drawing(mlx);
	return (0);
}

void	handle_offset(int dir, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (dir == 0)
		mlx->line->offsety -= 10;
	if (dir == 1)
		mlx->line->offsety += 10;
	if (dir == 2)
		mlx->line->offsetx += 10;
	if (dir == 3)
		mlx->line->offsetx -= 10;
}

void	handle_roll(int key, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (key == 86)
		mlx->line->roll--;
	if (key == 88)
		mlx->line->roll++;
}

void	handle_pitch(int key, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (key == 91)
		mlx->line->pitch += 0.1;
	if (key == 84)
		mlx->line->pitch -= 0.1;
}

void	handle_rotatez(int key, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (key == 89)
		mlx->line->rotatez -= 0.1;
	if (key == 92)
		mlx->line->rotatez += 0.1;
}

void	handle_rotatex(int key, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (key == 83)
		mlx->line->rotatex -= 0.01;
	if (key == 85)
		mlx->line->rotatex += 0.01;
}

void	handle_reset(t_mlx *mlx)
{
	t_line *line;

	line = mlx->line;
	line->offsetx = 750;
	line->offsety = 500;
	if (line->iso)
	{
		mlx->line->offsetx += 200;
		mlx->line->offsety += 200;
	}
	line->roll = 0;
	line->pitch = 0.2;
	line->rotatex = 0;
	line->rotatey = 0;
	line->rotatez = 0;
	line->autooffset = 0;
}

int		check_key(int key, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (key == 53)
		exit(0);
	if (key == 82)
	{
		mlx->line->autooffset = !(mlx->line->autooffset);
		handle_reset(mlx);
	}
	if (key == 2)
	{
		mlx->line->idle = !(mlx->line->idle);
		if (mlx->line->idle)
			mlx->line->rotatex = -0.3;
		if (!mlx->line->idle)
			handle_reset(mlx);
	}
	if (key == 1)
		mlx->line->colors = !(mlx->line->colors);
	if (122 < key && key < 127)
		handle_offset(126 - key, param);
	if (key == 86 || key == 88)
		handle_roll(key, param);
	if (key == 91 || key == 84)
		handle_pitch(key, param);
	if (key == 89 || key == 92)
		handle_rotatez(key, param);
	if (key == 83 || key == 85)
		handle_rotatex(key, param);
	if (key == 0)
	{
		if (!mlx->line->iso)
		{
			mlx->line->rotatex = 0;
			mlx->line->rotatey = 0;
			mlx->line->rotatez = 0;
		}
		else
		{
			mlx->line->rotatex = 0;
			mlx->line->rotatey = 0;
			mlx->line->rotatez = 0;
		}
		mlx->line->isoangle = 0.523599;
		mlx->line->iso = !(mlx->line->iso);
	}
	ft_memset(mlx->image, 0, WINDOW_HEIGHT * WINDOW_WIDTH * 4);
	handle_drawing(mlx);
	return (0);
}

int		mouse_press(int key, int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (key == 1)
	{
		mlx->mouse1 = 1;
		mlx->mousex = x;
		mlx->mousey = y;
	}
	if (key == 2)
		mlx->mouse2 = 1;
	if (key == 4)
		mlx->line->zoom += 0.5;
	if (key == 5 && mlx->line->zoom > 0.6)
		mlx->line->zoom -= 0.5;
	ft_memset(mlx->image, 0, WINDOW_HEIGHT * WINDOW_WIDTH * 4);
	handle_drawing(mlx);
	return (0);
}

int		mouse_release(int key, int x, int y, void *param)
{
	t_mlx *mlx;

	(void)x;
	(void)y;
	mlx = param;
	if (key == 1)
		mlx->mouse1 = 0;
	if (key == 2)
		mlx->mouse2 = 0;
	ft_memset(mlx->image, 0, WINDOW_HEIGHT * WINDOW_WIDTH * 4);
	handle_drawing(mlx);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (mlx->mouse1)
	{
		if (x > mlx->mousex)
			mlx->line->offsetx += x - mlx->mousex;
		else if (x < mlx->mousex)
			mlx->line->offsetx -= mlx->mousex - x;
		if (y > mlx->mousey)
			mlx->line->offsety += y - mlx->mousey;
		else if (y < mlx->mousey)
			mlx->line->offsety -= mlx->mousey - y;
		mlx->mousex = x;
		mlx->mousey = y;
	}
	if (mlx->mouse2)
	{
		if (x > mlx->mousex)
			mlx->line->rotatey += (x - mlx->mousex) * 0.002;
		else if (x < mlx->mousex)
			mlx->line->rotatey += (x - mlx->mousex) * 0.002;
		if (y > mlx->mousey)
		{
			mlx->line->rotatex += (y - mlx->mousey) * 0.002;
		}
		else if (y < mlx->mousey)
		{
			mlx->line->rotatex += (y - mlx->mousey) * 0.002;
		}
		mlx->mousex = x;
		mlx->mousey = y;
	}
	if (mlx->line->idle)
		mlx->line->rotatey -= 0.01;
	mlx->mousex = x;
	mlx->mousey = y;
	ft_memset(mlx->image, 0, WINDOW_HEIGHT * WINDOW_WIDTH * 4);
	handle_drawing(mlx);
	return (0);
}

void	handle_error(int code)
{
	if (!code)
		ft_printf("Error\n");
	if (code == 1)
	{
		ft_printf("Error: Amount of arguments is not 1\n");
	}
	if (code == 2)
		ft_printf("Error: Invalid map\n");
	if (code == 3)
		ft_printf("Error: Malloc failed\n");
	if (code == 4)
		ft_printf("Error: Map not found\n");
	exit(0);
}

void	draw_pixel(int x, int y, int color, t_mlx *mlx)
{
	int R;
	int G;
	int B;

	if (x <= 0 || y <= 0 || WINDOW_WIDTH <= x || WINDOW_HEIGHT <= y)
		return ;
	B = color % 256;
	G = color/256 % 256;
	R = color/256/256 % 256;
	mlx->image[x * 4 + y * mlx->size_line] = R;
	mlx->image[x * 4 + y * mlx->size_line + 1] = G;
	mlx->image[x * 4 + y * mlx->size_line + 2] = B;
}

void	plot_line_low(t_line *line, t_mlx *mlx)
{
	int dxy[2];
	int xy[2];
	int yi;
	int D;

	dxy[0] = line->x2 - line->x1;
	dxy[1] = line->y2 - line->y1;
	yi = 1;
	if (dxy[1] < 0)
	{
		yi = -1;
		dxy[1] *= -1;
	}
	D = 2 * dxy[1] - dxy[0];
	xy[0] = line->x1;
	xy[1] = line->y1;
	while (xy[0] <= line->x2)
	{
		draw_pixel(xy[0], xy[1], line->color, mlx);
		if (D > 0)
		{
			xy[1] += yi;
			D -= 2 * dxy[0];
		}
		xy[0]++;
		D += 2 * dxy[1];
	}
}

void	plot_line_high(t_line *line, t_mlx *mlx)
{
	int dxy[2];
	int xy[2];
	int xi;
	int D;

	dxy[0] = line->x2 - line->x1;
	dxy[1] = line->y2 - line->y1;
	xi = 1;
	if (dxy[0] < 0)
	{
		xi = -1;
		dxy[0] *= -1;
	}
	D = 2 * dxy[0] - dxy[1];
	xy[0] = line->x1;
	xy[1] = line->y1;
	while (xy[1] <= line->y2)
	{
		draw_pixel(xy[0], xy[1], line->color, mlx);
		if (D > 0)
		{
			xy[0] += xi;
			D -= 2 * dxy[1];
		}
		xy[1]++;
		D += 2 * dxy[0];
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
	if (abs(line->y2 -line->y1) < abs(line->x2 - line->x1))
	{
		if (line->x1 > line->x2)
		{
			swap_points(line);
			plot_line_low(line, mlx);
			//swap_points(line);
		}
		else
			plot_line_low(line, mlx);
	}
	else
	{
		if (line->y1 > line->y2)
		{
			swap_points(line);
			plot_line_high(line, mlx);
			//swap_points(line);
		}
		else
			plot_line_high(line, mlx);
	}
}

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
	// if (d < 0.125)
	// 	line->color = 0x087cff;
	// else if (d < 0.25)
	// 	line->color = 0x0096ff;
	// else if (d < 0.375)
	// 	line->color = 0x00a5ff;
	// else if (d < 0.5)
	// 	line->color = 0x00b4ff;
	// else if (d < 0.625)
	// 	line->color = 0xafffff;
	// else if (d < 0.75)
	// 	line->color = 0xc8ffff;
	// else if (d < 0.875)
	// 	line->color = 0xe1ffff;
	// else if (d <= 1)
	// 	line->color = 0xffffff;
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
	// if (d > -0.125)
	// 	line->color = 0x008cff;
	// else if (d > -0.25)
	// 	line->color = 0x0078ff;
	// else if (d > -0.375)
	// 	line->color = 0x0064ff;
	// else if (d > -0.5)
	// 	line->color = 0x0050ff;
	// else if (d > -0.625)
	// 	line->color = 0x003cff;
	// else if (d > -0.75)
	// 	line->color = 0x0028ff;
	// else if (d > -0.875)
	// 	line->color = 0x0014ff;
	// else if (d >= -1)
	// 	line->color = 0x0000ff;
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
		line->color = 0xa4ffa4;//line->color = 0x0078ff;

}
void	draw_line(t_line *line, t_mlx *mlx)
{
	int *map;
	//double d;
	//int x;
	//int y;

	// if (line->x1 > line->x2)
	// {
	// 	x = line->x2;
	// 	line->x2 = line->x1;
	// 	line->x1 = x;
	// }
	// x = line->x1;
	// while (x < line->x2)
	// {
	// 	y = line->y1 + (line->y2 - line->y1) * (x - line->x1) / (line->x2 - line->x1);
	// 	draw_pixel(x, y, line->color, mlx);
	// 	x++;
	// }
	if (line->autooffset)
	{
		line->offsetx = 750 - mlx->s_map->cols/2 * 5 - mlx->s_map->mapxy[0];
		line->offsety = 500 - mlx->s_map->rows/2 * 5 - mlx->s_map->mapxy[1];
	}
	map = mlx->s_map->mapxy;
	// if (line->z1 && line->z2)
	// 	line->color = 0x0000FF;//0xFFFFFFF - line->z1 * 1000;
	// else if (line->z1)
	// {
	// 	d = line->z1/2;
	// 	d = d / mlx->s_map->biggestz;
	// 	line->color = d * 255;
	// }
	// else if (line->z2)
	// {
	// 	d = line->z2/2;
	// 	d = d / mlx->s_map->biggestz;
	// 	line->color = d * 255;
	// }
	// else
	// 	line->color = 0xFFFFFFF;
	handle_color(line, mlx);
	line->x1 = line->x1 * line->zoom;
	line->x2 = line->x2 * line->zoom;
	line->y1 = line->y1 * line->zoom;
	line->y2 = line->y2 * line->zoom;
	line->z1 = line->z1 * line->zoom * line->pitch;
	line->z2 = line->z2 * line->zoom * line->pitch;
	if (line->iso)
		transform_iso(line);
	if (line->rotatex)
		rotate_x(line);
	if (line->rotatey)
		rotate_y(line);
	if (line->rotatez)
		rotate_z(line);
	line->x1 = line->x1 + line->offsetx;
	line->x2 = line->x2 + line->offsetx;
	line->y1 = line->y1 + line->offsety;
	line->y2 = line->y2 + line->offsety;
	//ft_printf("x:%d, y:%d, x2:%d, y2:%d, z1:%d, z2:%d\n", line->x1, line->y1, line->x2, line->y2, line->z1, line->z2);
	plot_line(line, mlx);
}

void	transform_iso(t_line *line)
{
	int prev_x;
	int prev_y;

	prev_x = line->x1;
	prev_y = line->y1;
	line->x1 = (prev_x - prev_y) * cos(line->isoangle);
	line->y1 = -line->z1 + (prev_x + prev_y) * sin(line->isoangle);
	prev_x = line->x2;
	prev_y = line->y2;
	line->x2 = (prev_x - prev_y) * cos(line->isoangle);
	line->y2 = -line->z2 + (prev_x + prev_y) * sin(line->isoangle);
}

void	rotate_x(t_line *line)
{
	int prev_y;
	int prev_z;

	prev_y = line->y1;
	prev_z = line->z1;
	line->y1 = prev_y * cos(line->rotatex) + prev_z * sin(line->rotatex);
	line->z1 = -prev_y * sin(line->rotatex) + prev_z * cos(line->rotatex);
	prev_y = line->y2;
	prev_z = line->z2;
	line->y2 = prev_y * cos(line->rotatex) + prev_z * sin(line->rotatex);
	line->z2 = -prev_y * sin(line->rotatex) + prev_z * cos(line->rotatex);
}

void	rotate_y(t_line *line)
{
	int prev_x;
	int prev_z;

	prev_x = line->x1;
	prev_z = line->z1;
	line->x1 = prev_x * cos(line->rotatey) + prev_z * sin(line->rotatey);
	line->z1 = -prev_x * sin(line->rotatey) + prev_z * cos(line->rotatey);
	prev_x = line->x2;
	prev_z = line->z2;
	line->x2 = prev_x * cos(line->rotatey) + prev_z * sin(line->rotatey);
	line->z2 = -prev_x * sin(line->rotatey) + prev_z * cos(line->rotatey);
}

void	rotate_z(t_line *line)
{
	int prev_x;
	int prev_y;

	prev_x = line->x1;
	prev_y = line->y1;
	line->x1 = prev_x * cos(line->rotatez) + prev_y * sin(line->rotatez);
	line->y1 = -prev_x * sin(line->rotatez) + prev_y * cos(line->rotatez);
	prev_x = line->x2;
	prev_y = line->y2;
	line->x2 = prev_x * cos(line->rotatez) + prev_y * sin(line->rotatez);
	line->y2 = -prev_x * sin(line->rotatez) + prev_y * cos(line->rotatez);
}

void	handle_line_draw(int xy[4], t_line *line, t_mlx *mlx)
{
		int *map;

		map = mlx->s_map->mapxy;
		line->x1 = map[xy[0] * 3 + xy[2] * mlx->s_map->cols * 3];// * line->zoom + line->offsetx;
		line->x2 = map[xy[1] * 3 + xy[3] * mlx->s_map->cols * 3];// + line->roll * xy[3];// * line->zoom + line->offsetx;
		line->y1 = map[xy[2] * mlx->s_map->cols * 3 + xy[0] * 3 + 1];// * line->zoom + line->offsety;
		line->y2 = map[xy[3] * mlx->s_map->cols * 3 + xy[1] * 3 + 1] + line->roll * xy[1];// * line->zoom + line->offsety;
		line->z1 = map[xy[0] * 3 + xy[2] * mlx->s_map->cols * 3 + 2];
		line->z2 = map[xy[1] * 3 + xy[3] * mlx->s_map->cols * 3 + 2];
		//map[xy[1] * 3 + xy[3] * mlx->s_map->cols * 3] =

		////("testix:%d, ix2:%d, iy:%d, iy2:%d, iz1:%d, iz2:%d\n", xy[0] * 3, xy[1] * 3, xy[0] * 3 + 1, xy[1] * 3 + 1, xy[0] * 3 + 2, xy[1] * 3 + 2);
		////("ix:%d, ix2:%d, iy:%d, iy2:%d, iz1:%d, iz2:%d\n", map[xy[0] * 3], map[xy[1] * 3], map[xy[0] * 3 + 1], map[xy[1] * 3 + 1], map[xy[0] * 3 + 2], map[xy[1] * 3 + 1]);
		//ft_printf("x:%d, y:%d, x2:%d, y2:%d, z1:%d, z2:%d\n", line->x1, line->y1, line->x2, line->y2, line->z1, line->z2);
		if (xy[2] == xy[3])
		{
			map[xy[1] * 3 + xy[3] * mlx->s_map->cols * 3] = line->x2;
			map[xy[3] * mlx->s_map->cols * 3 + xy[1] * 3 + 1] = line->y2;
		}
		// if (xy[0] == xy[1])
		// {
		//  	map[xy[0] * 3 + xy[2] * mlx->s_map->cols * 3] = line->x1;
		// 	map[xy[2] * mlx->s_map->cols * 3 + xy[0] * 3 + 1] = line->y1;
		// }
		// if (xy[2] == xy[3])
		// {
		// 	map[xy[1] * 3 + xy[3] * mlx->s_map->cols * 3] = line->x2;
		// 	map[xy[3] * mlx->s_map->cols * 3 + xy[1] * 3 + 1] = line->y2;
		// }
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

void	map_to_coordinates(t_map *s_map)
{
	int i;
	int j;
	int x;
	int y;
	int count;

	if (!(s_map->mapxy = (int*)malloc(sizeof(int) * s_map->rows * s_map->cols * 3)))
		handle_error(3);
	i = 0;
	y = s_map->rows/2 * -5;
	count = 0;
	while (i < s_map->rows)
	{
		j = 0;
		x = s_map->cols/2 * -5;
		while (j < s_map->cols)
		{
			s_map->mapxy[count] = x;
			s_map->mapxy[count + 1] = y;
			////("%d, %d, %d\n", count - 2, count - 1, count);

			s_map->mapxy[count + 2] = s_map->map[i][j];
			//ft_printf("%d, %d, %d\n", x, y, s_map->map[i][j]);
			j++;
			x += 5;
			count += 3;
		}
		y += 5;
		i++;
	}
}

void	draw_background(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < WINDOW_WIDTH * WINDOW_HEIGHT * 4)
	{
		mlx->image[i] = (char)32;
		mlx->image[i + 1] = (char)32;
		mlx->image[i + 2] = (char)32;
		i += 4;
	}
}

int	handle_drawing(void *param)
{
	t_mlx *mlx;

	mlx = param;
	//map_to_coordinates(mlx->s_map);
	draw_background(mlx);
	draw_map(mlx->line, mlx);
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->image_ptr, 0, 0);
	return (0);
}

void	initialize_line(t_line *line, t_mlx *mlx)
{
	(void)mlx;
	mlx->mouse1 = 0;
	mlx->mouse2 = 0;
	line->color = 0xFFFFFF;
	line->zoom = 600 / (mlx->s_map->cols * 5);
	if (!line->zoom)
		line->zoom = 1;
	line->offsetx = 750;
	line->offsety = 500;
	line->iso = 0;
	line->roll = 0;
	line->pitch = mlx->s_map->biggestz * 0.1;
	if (line->pitch > 10)
		line->pitch = 10;
	line->rotatex = -0.3;
	line->rotatey = 0;
	line->rotatez = 0;
	line->autooffset = 0;
	line->colors = 0;
	line->idle = 1;
}

void	handle_graphics(t_map *s_map)
{
	t_mlx	*mlx;
	t_line *line;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		handle_error(3);
	if (!(line = (t_line*)malloc(sizeof(t_line))))
		handle_error(3);
	mlx->init = mlx_init();
	mlx->window = mlx_new_window(mlx->init, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	mlx->image_ptr = mlx_new_image(mlx->init, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx->image = mlx_get_data_addr(mlx->image_ptr, &(mlx->bpp), &(mlx->size_line), &(mlx->endian));
	mlx->s_map = s_map;
	mlx->line = line;
	initialize_line(mlx->line, mlx);
	mlx_hook(mlx->window, 2, 0, check_key, (void*)mlx);
	mlx_hook(mlx->window, 4, 0, mouse_press, (void*)mlx);
	mlx_hook(mlx->window, 5, 0, mouse_release, (void*)mlx);
	mlx_hook(mlx->window, 6, 0, mouse_move, (void*)mlx);
	mlx_hook(mlx->window, 12, 0, handle_idle, (void*)mlx);
	mlx_loop_hook(mlx->init, handle_idle, (void*)mlx);
	map_to_coordinates(mlx->s_map);
	handle_drawing((void*)mlx);
	mlx_loop(mlx->init);
}

int		main(int argc, char **argv)
{
	t_map	*s_map;

	if (argc != 2)
		handle_error(1);
	if (!(s_map = (t_map*)malloc(sizeof(*s_map))))
		handle_error(3);
	store_map(argv[1], s_map);
	print_map(s_map); //temporary to check if input has been stored correctly
	handle_graphics(s_map);
	return (0);
}

//create function to check highest altitude in file, then change color according to difference to max altitude :)
//add function to change map coordinates if coordinates go over screen

//add x, y z to screen
//add projection type to screen when changed
//change colors, maybe top=white, 0=orange, bottom=red
