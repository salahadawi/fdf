/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:58:47 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/19 16:57:02 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_rotation(int key, t_mlx *mlx)
{
	if (key == 84 || key == 91)
		handle_rotatex(key, mlx);
	if (key == 86 || key == 88)
		handle_rotatey(key, mlx);
	if (key == 89 || key == 92)
		handle_rotatez(key, mlx);
}

void	check_360(t_line *line)
{
	if (line->rotatex > 360 / 57.33)
		line->rotatex = 0;
	if (line->rotatex < 0)
		line->rotatex = 358.5 / 57.33;
	if (line->rotatey > 360 / 57.33)
		line->rotatey = 0;
	if (line->rotatey < 0)
		line->rotatey = 358.5 / 57.33;
	if (line->rotatez > 360 / 57.33)
		line->rotatez = 0;
	if (line->rotatez < 0)
		line->rotatez = 357 / 57.33;
}

void	handle_rotatex(int key, t_mlx *mlx)
{
	if (key == 91)
		mlx->line->rotatex -= 0.03;
	if (key == 84)
		mlx->line->rotatex += 0.03;
	check_360(mlx->line);
}

void	handle_rotatey(int key, t_mlx *mlx)
{
	if (key == 86)
		mlx->line->rotatey -= 0.03;
	if (key == 88)
		mlx->line->rotatey += 0.03;
	check_360(mlx->line);
}

void	handle_rotatez(int key, t_mlx *mlx)
{
	if (key == 89)
		mlx->line->rotatez += 0.05;
	if (key == 92)
		mlx->line->rotatez -= 0.05;
	check_360(mlx->line);
}
