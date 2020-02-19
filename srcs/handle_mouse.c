/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:00:15 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/19 16:22:48 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		mouse_press(int key, int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (key == 1)
	{
		mlx->mouse1 = 1;
		mlx->mousex = x;
		mlx->mousey = y;
	}
	if (key == 2)
		mlx->mouse2 = 1;
	if (key == 4)
		mlx->line->zoom += 0.5;
	if (key == 5 && mlx->line->zoom > 0.6)
		mlx->line->zoom -= 0.5;
	handle_drawing(mlx);
	return (0);
}

int		mouse_release(int key, int x, int y, void *param)
{
	t_mlx *mlx;

	(void)x;
	(void)y;
	mlx = param;
	if (key == 1)
		mlx->mouse1 = 0;
	if (key == 2)
		mlx->mouse2 = 0;
	handle_drawing(mlx);
	return (0);
}

void	handle_mouse1_move(int x, int y, t_mlx *mlx)
{
	if (x != mlx->mousex)
		mlx->line->offsetx += x - mlx->mousex;
	if (y != mlx->mousey)
		mlx->line->offsety += y - mlx->mousey;
}

void	handle_mouse2_move(int x, int y, t_mlx *mlx)
{
	if (x != mlx->mousex)
		mlx->line->rotatey += (x - mlx->mousex) * 0.002;
	if (y != mlx->mousey)
		mlx->line->rotatex += (y - mlx->mousey) * 0.002;
}

int		mouse_move(int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (mlx->mouse1)
		handle_mouse1_move(x, y, mlx);
	if (mlx->mouse2)
		handle_mouse2_move(x, y, mlx);
	if (mlx->line->idle)
		mlx->line->rotatey -= 0.01;
	mlx->mousex = x;
	mlx->mousey = y;
	check_360(mlx->line);
	handle_drawing(mlx);
	return (0);
}
