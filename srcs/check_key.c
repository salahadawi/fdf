/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:10:01 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/19 16:22:07 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		check_key(int key, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (key == 65307)
		exit(0);
	if (key == 65438)
		handle_reset(mlx);
	if (key == 65450)
		mlx->line->idle = !(mlx->line->idle);
	if (key == 65455)
		mlx->line->colors = !(mlx->line->colors);
	if (key == 104)
		mlx->gui = !(mlx->gui);
	if (65360 < key && key < 65365)
		handle_offset(65364 - key, mlx);
	if (key == 65430 || key == 65431 || key == 65432 || key == 65433 ||
		key == 65429 || key == 65434)
		check_rotation(key, mlx);
	if (key == 65436 || key == 65435)
		handle_pitch(key, mlx);
	if (key == 65437)
		handle_iso(mlx);
	handle_drawing(mlx);
	return (0);
}
