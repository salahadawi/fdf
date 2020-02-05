/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:42 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/04 14:25:25 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		draw_line(int dir, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (dir == 0)
		mlx_pixel_put(mlx->init, mlx->window, mlx->x, --mlx->y, 0xFFFFFF);
	if (dir == 1)
		mlx_pixel_put(mlx->init, mlx->window, mlx->x, ++mlx->y, 0xFFFFFF);
	if (dir == 2)
		mlx_pixel_put(mlx->init, mlx->window, ++mlx->x, mlx->y, 0xFFFFFF);
	if (dir == 3)
		mlx_pixel_put(mlx->init, mlx->window, --mlx->x, mlx->y, 0xFFFFFF);
	return (0);
}

int		check_key(int key, void *param)
{
	if (key == 53)
		exit(0);
	if (122 < key && key < 127)
		draw_line(126 - key, param);
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
		exit(0);
	}

void	handle_graphics(t_map *s_map)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->init = mlx_init();
	mlx->height = (s_map->rows * 60 < 2560) ;
	mlx->width = s_map->cols * 60;
	mlx->window = mlx_new_window(mlx->init, mlx->width, mlx->height, "Hello World!");
	mlx->x = mlx->height/2;
	mlx->y = mlx->width/2;
	mlx_hook(mlx->window, 2, 0, check_key, (void*)mlx);
	mlx_loop(mlx->init);
}

int		main(int argc, char **argv)
{
	t_map	*s_map;

	if (argc != 2)
		handle_error(1);
	s_map = (t_map*)malloc(sizeof(*s_map));
	store_map(argv[1], s_map);
	print_map(s_map); //temporary to check if input has been stored correctly
	handle_graphics(s_map);
	return (0);
}