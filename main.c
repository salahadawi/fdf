/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:42 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/06 14:19:59 by sadawi           ###   ########.fr       */
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
	if (key == 4)
		mlx->line->zoom++;
	if (key == 5)
		mlx->line->zoom--;
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
		mlx->line->zoom++;
	if (key == 5)
		mlx->line->zoom--;
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

	B = color % 256;
	G = color/256 % 256;
	R = color/256/256 % 256;
	mlx->image[x * 4 + y * mlx->size_line] = R;
	mlx->image[x * 4 + y * mlx->size_line + 1] = G;
	mlx->image[x * 4 + y * mlx->size_line + 2] = B;
}

void	draw_line(t_line *line, t_mlx *mlx)
{
	int x;
	int y;

	x = line->x1;
	y = line->y1;
	while (x < line->x2)
	{
		draw_pixel(++x, y, line->color, mlx);
	}
	while (y < line->y2)
	{
		draw_pixel(x, ++y, line->color, mlx);
	}
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
