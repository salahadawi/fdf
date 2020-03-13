/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_graphics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:16:10 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/19 16:22:21 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_graphics(t_map *s_map)
{
	t_mlx	*mlx;
	t_line	*line;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		handle_error(3);
	if (!(line = (t_line*)malloc(sizeof(t_line))))
		handle_error(3);
	mlx->init = mlx_init();
	mlx->window = mlx_new_window(mlx->init, WIN_WIDTH, WIN_HEIGHT, s_map->name);
	mlx->image_ptr = mlx_new_image(mlx->init, WIN_WIDTH, WIN_HEIGHT);
	mlx->image = mlx_get_data_addr(mlx->image_ptr, &(mlx->bpp),
	&(mlx->size_line), &(mlx->endian));
	mlx->s_map = s_map;
	mlx->line = line;
	initialize_line(mlx->line, mlx);
	mlx_hook(mlx->window, 2, KeyPressMask, check_key, (void*)mlx);
	mlx_hook(mlx->window, 4, ButtonPressMask, mouse_press, (void*)mlx);
	mlx_hook(mlx->window, 5, ButtonReleaseMask, mouse_release, (void*)mlx);
	mlx_hook(mlx->window, 6, ButtonMotionMask, mouse_move, (void*)mlx);
	//mlx_hook(mlx->window, 12, 0, handle_idle, (void*)mlx);
	mlx_loop_hook(mlx->init, handle_idle, (void*)mlx);
	map_to_coordinates(mlx->s_map);
	handle_drawing((void*)mlx);
	mlx_loop(mlx->init);
}

void	draw_background(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < WIN_WIDTH * WIN_HEIGHT * 4)
	{
		mlx->image[i] = (char)32;
		mlx->image[i + 1] = (char)32;
		mlx->image[i + 2] = (char)32;
		i += 4;
	}
}

void	initialize_line(t_line *line, t_mlx *mlx)
{
	(void)mlx;
	mlx->mouse1 = 0;
	mlx->mouse2 = 0;
	line->color = 0xFFFFFF;
	line->zoom = 800 / (mlx->s_map->cols * 5);
	if (!line->zoom)
		line->zoom = 1;
	line->offsetx = 750;
	line->offsety = 500;
	line->iso = 0;
	line->pitch = 1;
	if (mlx->s_map->biggestz > 20)
		line->pitch = 0.1;
	line->rotatex = 6;
	line->rotatey = 0;
	line->rotatez = 0;
	line->autooffset = 0;
	line->colors = 1;
	line->idle = 1;
	mlx->gui = 1;
}
