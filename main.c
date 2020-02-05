/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:42 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/05 18:26:38 by sadawi           ###   ########.fr       */
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
        draw_map(mlx);
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

void    draw_pixel(int x, int y, int color, t_mlx *mlx)
{
    int R;
    int G;
    int B;

    B = color % 256;
    G = color/256 % 256;
    R = color/256/256 % 256;
    mlx->image[x * 4 + y * 4 * mlx->size_line] = R;
    mlx->image[x * 4 + y * 4 * mlx->size_line + 1] = G;
    mlx->image[x * 4 + y * 4 * mlx->size_line + 2] = B;
}

void    draw_line(t_line *line, t_mlx *mlx)
{
    int x;
    int y;

    x = line->x1;
    y = line->y1;
    while (x < line->x2)
    {
        draw_pixel(++x, y, line->color, mlx);
        while (y < line->y2)
        {
            draw_pixel(x, ++y, line->color, mlx);
        }
    }
    mlx_put_image_to_window(mlx->init, mlx->window, mlx->image, 0, 0);
}

int    draw_map(void *param)
{
    t_mlx *mlx;
    t_line *line;
    
    mlx = param;
    if (!(line = (t_line*)malloc(sizeof(t_line))))
        handle_error(3);
    line->x1 = 0;
    line->y1 = 100;
    line->x2 = 500;
    line->y2 = 200;
    line->color = 0xFFFFFFF;
    draw_line(line, mlx);
    mlx_put_image_to_window(mlx->init, mlx->window, mlx->image_ptr, 0, 0);
    
    return (0);
}

void	handle_graphics(t_map *s_map)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
        handle_error(3);
	mlx->init = mlx_init();
	mlx->window = mlx_new_window(mlx->init, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	mlx->image_ptr = mlx_new_image(mlx->init, WINDOW_WIDTH, WINDOW_HEIGHT);
    mlx->image = mlx_get_data_addr(mlx->image_ptr, &(mlx->bpp), &(mlx->size_line), &(mlx->endian));
    mlx->s_map = s_map;
    draw_map(mlx);
	mlx_hook(mlx->window, 2, 0, check_key, (void*)mlx);
    mlx_hook(mlx->window, 12, 0, draw_map, (void*)mlx);
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