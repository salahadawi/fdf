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
			ft_printf("Error");
		if (code == 1)
		{
			ft_printf("Error: Amount of arguments is not 1");
		}
		if (code == 2)
			ft_printf("Error: Invalid map");
		if (code == 3)
			ft_printf("Error: Invalid file");
		exit(0);
	}

int		check_map(char **map)
{
	
}

void	check_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
		if (!ft_isdigit(line[i]) && line[i] != ' ')
			handle_error(3);
}

int		count_ints(char **line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			i++;
		if (ft_isdigit(line[i]))
		{
			while (ft_isdigit(line[i]))
				i++;
			count++;
		}
	}
	return (count)
}

void	store_map_line(char *line, t_map *s_map)
{
	int i;
	int col;
	int count;

	i = 0;
	col = 0;
	check_line(line);
	count = count_ints(line);
	if (s_map->cols)
		if (count != s_map->cols)
			handle_error(3);
	s_map->map[s_map->rows] = (int*)malloc(sizeof(int) * count;
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
					i++;
		if (ft_isdigit(line[i]))
			s_map->map[s_map->rows][col++] = ft_atoi(&line[i]);
	}
	s_map->cols = col;
}

void	store_map(char *file, t_map *s_map)
{
	int fd;
	char *line;

	s_map->rows = 0;
	s_map->cols = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		store_map_line(line, s_map);
	}
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_map	*s_map;

	if (argc != 2)
		handle_error(1);
	store_map(argv[1], s_map);
	if (!check_map(s_map->map))
		handle_error(2);
	mlx = (t_mlx*)malloc(sizeof(*mlx));
	mlx->init = mlx_init();
	mlx->height = 500;
	mlx->width = 500;
	mlx->window = mlx_new_window(mlx->init, mlx->height, mlx->width, "Hello World!");
	mlx->x = mlx->height/2;
	mlx->y = mlx->width/2;
	mlx_hook(mlx->window, 2, 0, check_key, (void*)mlx);
	mlx_loop(mlx->init);
	return (0);
}