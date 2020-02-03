/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:42 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/03 18:46:07 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

int		draw_line(int dir, void **param)
{
	if (dir == 0)
		mlx_pixel_put(param[0], param[1], (int)param[2], (int)--param[3], 0xFFFFFF);
	if (dir == 1)
		mlx_pixel_put(param[0], param[1], (int)param[2], (int)++param[3], 0xFFFFFF);
	if (dir == 2)
		mlx_pixel_put(param[0], param[1], (int)++param[2], (int)param[3], 0xFFFFFF);
	if (dir == 3)
		mlx_pixel_put(param[0], param[1], (int)--param[2], (int)param[3], 0xFFFFFF);
	return (0);
}

int		check_key(int key, void **param)
{
	(void)param;
	if (key == 53)
		exit(0);
	if (122 < key && key < 127)
		draw_line(126 - key, param);
	return (0);
}

int		main(void)
{
	void	*mlx[4];

	mlx[0] = mlx_init();
	mlx[1] = mlx_new_window(mlx[0], 500, 500, "Hello World!");
	mlx[2] = (void*)250;
	mlx[3] = (void*)250;
	mlx_hook(mlx[1], 2, 0, check_key, mlx);
	mlx_loop(mlx[0]);
	return (0);
}
