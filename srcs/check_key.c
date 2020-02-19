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
	if (key == 53)
		exit(0);
	if (key == 82)
		handle_reset(mlx);
	if (key == 67)
		mlx->line->idle = !(mlx->line->idle);
	if (key == 75)
		mlx->line->colors = !(mlx->line->colors);
	if (key == 4)
		mlx->gui = !(mlx->gui);
	if (122 < key && key < 127)
		handle_offset(126 - key, mlx);
	if (key == 84 || key == 91 || key == 86 || key == 88 ||
		key == 89 || key == 92)
		check_rotation(key, mlx);
	if (key == 83 || key == 85)
		handle_pitch(key, mlx);
	if (key == 87)
		handle_iso(mlx);
	handle_drawing(mlx);
	return (0);
}
