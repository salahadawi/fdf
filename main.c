/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:42 by sadawi            #+#    #+#             */
/*   Updated: 2020/01/29 17:34:55 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

int		check_key(int key, void **param)
{
	(void)param;
	if (key == 53)
		exit(0);
	return (0);
}

int		main(void)
{
	void	*mlx[2];

	mlx[0] = mlx_init();
	mlx[1] = mlx_new_window(mlx[0], 500, 500, "Hello World!");
	mlx_hook(mlx[1], 2, 0, check_key, mlx);
	mlx_loop(mlx[0]);
	return (0);
}
