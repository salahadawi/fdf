/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_gui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:07:36 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/19 17:16:01 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_gui_double(t_mlx *mlx, int x, int y, double d)
{
	char *str;

	str = ft_itoa_double(d, 1);
	mlx_string_put(mlx->init, mlx->window, x, y, 0xFFFFFF, str);
	free(str);
}

void	mlxstr(t_mlx *mlx, int x, int y, char *str)
{
	mlx_string_put(mlx->init, mlx->window, x, y, 0xFFFFFF, str);
}

void	draw_gui(t_mlx *mlx)
{
	if (!mlx->line->iso)
		mlxstr(mlx, 20, 30, "Parallel Projection");
	if (mlx->line->iso)
		mlxstr(mlx, 20, 30, "Isometric Projection");
	mlxstr(mlx, 1450 - ft_strlen(mlx->s_map->name) * 10, 950, mlx->s_map->name);
	mlxstr(mlx, 20, 75, "1 / 3 - Change pitch");
	mlxstr(mlx, 20, 100, "2 / 8 - Rotate X-axis");
	mlxstr(mlx, 20, 125, "4 / 6 - Rotate Y-axis");
	mlxstr(mlx, 20, 150, "7 / 9 - Rotate Z-axis");
	mlxstr(mlx, 20, 195, "5 - Toggle view");
	mlxstr(mlx, 20, 220, "0 - Reset view");
	mlxstr(mlx, 20, 245, "* - Toggle autospin");
	mlxstr(mlx, 20, 270, "/ - Toggle colours");
	mlxstr(mlx, 20, 315, "Mouse wheel - Zoom in/out");
	mlxstr(mlx, 20, 340, "Arrow keys - Move map");
	mlxstr(mlx, 20, 385, "X-axis:");
	mlxstr(mlx, 20, 410, "Y-axis:");
	mlxstr(mlx, 20, 435, "Z-axis:");
	mlxstr(mlx, 20, 460, "Pitch:");
	draw_gui_double(mlx, 100, 385, mlx->line->rotatex * 57.33);
	draw_gui_double(mlx, 100, 410, mlx->line->rotatey * 57.33);
	draw_gui_double(mlx, 100, 435, mlx->line->rotatez * 57.33);
	draw_gui_double(mlx, 100, 460, mlx->line->pitch);
}
