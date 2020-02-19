/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:56:50 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/19 16:23:05 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	store_map(char *file, t_map *s_map)
{
	int		fd;
	char	*line;

	s_map->rows = 0;
	s_map->cols = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		handle_error(4);
	s_map->biggestz = 1;
	while (get_next_line(fd, &line) > 0)
	{
		malloc_extra_row(s_map);
		store_map_line(line, s_map);
		free(line);
	}
	close(fd);
}

void	store_map_line(char *line, t_map *s_map)
{
	int i;
	int col;
	int count;

	i = 0;
	col = 0;
	check_line(line);
	count = count_ints(line, s_map);
	if (!(s_map->map[s_map->rows] = (int*)malloc(sizeof(int) * count)))
		handle_error(3);
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i])
		{
			s_map->map[s_map->rows][col++] = ft_atoi(&line[i]);
			if (s_map->biggestz < s_map->map[s_map->rows][col - 1])
				s_map->biggestz = s_map->map[s_map->rows][col - 1];
		}
		while (line[i] != ' ' && line[i])
			i++;
	}
	s_map->rows++;
	s_map->cols = col;
}

void	malloc_extra_row(t_map *s_map)
{
	int **tmp;
	int i;

	if (!(tmp = (int**)malloc(sizeof(int*) * (s_map->rows))))
		handle_error(3);
	ft_memcpy(tmp, s_map->map, sizeof(int**) * s_map->rows);
	if (s_map->rows)
		free(s_map->map);
	if (!(s_map->map = (int**)malloc(sizeof(int*) * (s_map->rows + 1))))
		handle_error(3);
	i = 0;
	while (i < s_map->rows)
	{
		s_map->map[i] = tmp[i];
		i++;
	}
	free(tmp);
}

void	map_to_coordinates(t_map *s_map)
{
	int i;
	int j;
	int x;
	int y;
	int count;

	if (!(s_map->mapxy = (int*)malloc(4 * s_map->rows * s_map->cols * 3)))
		handle_error(3);
	i = -1;
	y = s_map->rows / 2 * -5;
	count = 0;
	while (++i < s_map->rows)
	{
		j = -1;
		x = s_map->cols / 2 * -5;
		while (++j < s_map->cols)
		{
			s_map->mapxy[count] = x;
			s_map->mapxy[count + 1] = y;
			s_map->mapxy[count + 2] = s_map->map[i][j];
			x += 5;
			count += 3;
		}
		y += 5;
	}
}
