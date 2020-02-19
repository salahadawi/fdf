/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:26:51 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/19 17:10:17 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		handle_idle(t_mlx *mlx)
{
	if (mlx->line->idle)
		mlx->line->rotatey -= 0.005;
	check_360(mlx->line);
	handle_drawing(mlx);
	return (0);
}

void	handle_offset(int dir, t_mlx *mlx)
{
	if (dir == 0)
		mlx->line->offsety -= 10;
	if (dir == 1)
		mlx->line->offsety += 10;
	if (dir == 2)
		mlx->line->offsetx += 10;
	if (dir == 3)
		mlx->line->offsetx -= 10;
}

void	handle_pitch(int key, t_mlx *mlx)
{
	if (key == 85)
		mlx->line->pitch += 0.1;
	if (key == 83)
		mlx->line->pitch -= 0.1;
}

void	handle_reset(t_mlx *mlx)
{
	t_line *line;

	line = mlx->line;
	line->offsetx = 750;
	line->offsety = 500;
	line->pitch = 1;
	if (mlx->s_map->biggestz > 20)
		line->pitch = 0.1;
	line->rotatex = 0;
	line->rotatey = 0;
	line->rotatez = 0;
	line->autooffset = 0;
}

void	handle_iso(t_mlx *mlx)
{
	mlx->line->rotatex = 0;
	mlx->line->rotatey = 0;
	mlx->line->rotatez = 0;
	mlx->line->iso = !(mlx->line->iso);
}
