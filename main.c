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

//move to libft
int		ft_isdigit_neg(char *str)
{
	return (str[0] == '-' && ft_isdigit(str[1]));
}

void	check_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && !ft_isdigit_neg(&line[i]))
			handle_error(2);
		i++;
	}
}

int		count_ints(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			i++;
		if (ft_isdigit(line[i]) || ft_isdigit_neg(&line[i]))
		{
			if (line[i] == '-')
				i++;
			while (ft_isdigit(line[i]))
				i++;
			count++;
		}
	}
	return (count);
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
			handle_error(2);
	s_map->map[s_map->rows] = (int*)malloc(sizeof(int) * count);
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (ft_isdigit(line[i]) || ft_isdigit_neg(&line[i]))
			s_map->map[s_map->rows][col++] = ft_atoi(&line[i]);
		if (line[i] == '-')
			i++;
		while (ft_isdigit(line[i]))
			i++;
	}
	s_map->rows++;
	s_map->cols = col;
}

void	store_map(char *file, t_map *s_map)
{
	int fd;
	char *line;

	//fix to malloc correct amount of rows
	s_map->map = (int**)malloc(sizeof(int*) * 11);
	s_map->rows = 0;
	s_map->cols = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		store_map_line(line, s_map);
		free(line);
	}
	close(fd);
}

void	print_map(t_map *s_map)
{
	int i;
	int j;

	i = 0;
	while (i < s_map->rows)
	{
		j = 0;
		while (j < s_map->cols)
		{
			ft_printf("%3d ", s_map->map[i][j++]);
		}
		ft_printf("\n");
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_map	*s_map;

	if (argc != 2)
		handle_error(1);
	s_map = (t_map*)malloc(sizeof(*s_map));
	store_map(argv[1], s_map);
	print_map(s_map);
	mlx = (t_mlx*)malloc(sizeof(t_mlx));
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