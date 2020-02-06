/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:42 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/06 18:34:46 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_key(int key, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (key == 53)
		exit(0);
	if (key == 126)
		handle_drawing(mlx);
	handle_drawing(mlx);
	return (0);
}

int		check_mouse(int key, int x, int y, void *param)
{
	t_mlx *mlx;

	(void)x;
	(void)y;
	mlx = param;
	if (key == 4)
		mlx->line->zoom += 2;
	if (key == 5 && mlx->line->zoom > 2)
		mlx->line->zoom -= 2;
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
		ft_printf("Error: Malloc failed");
	exit(0);
}

void	draw_pixel(int x, int y, int color, t_mlx *mlx)
{
	int R;
	int G;
	int B;

	if (x < 0 || y < 0 || 1500 < x || 1000 < y)
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
			swap_points(line);
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
			swap_points(line);
		}
		else
			plot_line_high(line, mlx);
	}
}

void	draw_line(t_line *line, t_mlx *mlx)
{
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
	plot_line(line, mlx);
}

void	handle_line_draw(int xy[5], t_line *line, t_mlx *mlx)
{
		line->x1 = xy[0] * line->zoom;
		line->x2 = xy[1] * line->zoom;
		line->y1 = xy[2] * line->zoom;
		line->y2 = xy[3] * line->zoom;
		line->color = xy[4];
		draw_line(line, mlx);
}

void	draw_map(t_line *line, t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while (i < mlx->s_map->rows)
	{
		j = 0;
		while (j < mlx->s_map->cols)
		{
			if (j + 1 < mlx->s_map->cols)
				handle_line_draw(((int[5]){j, j + 1, i, i, 0xFFFFFF}), line, mlx);
			if (i + 1 < mlx->s_map->rows)
				handle_line_draw(((int[5]){j, j, i, i + 1, 0xFFFFFF}), line, mlx);
			j++;
		}
		i++;
	}
	// handle_line_draw(((int[5]){1, 5, 2, 3, 0xFFFFFF}), line, mlx);
	// handle_line_draw(((int[5]){2, 3, 5, 7, 0xFFFFFF}), line, mlx);
}

int	handle_drawing(void *param)
{
	t_mlx *mlx;

	mlx = param;
	draw_map(mlx->line, mlx);
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->image_ptr, 0, 0);
	return (0);
}

void	initialize_line(t_line *line)
{
	line->zoom = 10;
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
	initialize_line(mlx->line);
	mlx_hook(mlx->window, 2, 0, check_key, (void*)mlx);
	mlx_hook(mlx->window, 4, 0, check_mouse, (void*)mlx);
	mlx_hook(mlx->window, 12, 0, handle_drawing, (void*)mlx);
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
