/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:03:22 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/19 16:22:37 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_transform(t_line *line)
{
	if (line->iso)
		transform_iso(line);
	if (line->rotatex)
		rotate_x(line);
	if (line->rotatey)
		rotate_y(line);
	if (line->rotatez)
		rotate_z(line);
}

void	transform_iso(t_line *line)
{
	int prev_x;
	int prev_y;

	prev_x = line->x1;
	prev_y = line->y1;
	line->x1 = (prev_x - prev_y) * cos(0.523599);
	line->y1 = -line->z1 + (prev_x + prev_y) * sin(0.523599);
	prev_x = line->x2;
	prev_y = line->y2;
	line->x2 = (prev_x - prev_y) * cos(0.523599);
	line->y2 = -line->z2 + (prev_x + prev_y) * sin(0.523599);
}

void	rotate_x(t_line *line)
{
	int prev_y;
	int prev_z;

	prev_y = line->y1;
	prev_z = line->z1;
	line->y1 = prev_y * cos(line->rotatex) + prev_z * sin(line->rotatex);
	line->z1 = -prev_y * sin(line->rotatex) + prev_z * cos(line->rotatex);
	prev_y = line->y2;
	prev_z = line->z2;
	line->y2 = prev_y * cos(line->rotatex) + prev_z * sin(line->rotatex);
	line->z2 = -prev_y * sin(line->rotatex) + prev_z * cos(line->rotatex);
}

void	rotate_y(t_line *line)
{
	int prev_x;
	int prev_z;

	prev_x = line->x1;
	prev_z = line->z1;
	line->x1 = prev_x * cos(line->rotatey) + prev_z * sin(line->rotatey);
	line->z1 = -prev_x * sin(line->rotatey) + prev_z * cos(line->rotatey);
	prev_x = line->x2;
	prev_z = line->z2;
	line->x2 = prev_x * cos(line->rotatey) + prev_z * sin(line->rotatey);
	line->z2 = -prev_x * sin(line->rotatey) + prev_z * cos(line->rotatey);
}

void	rotate_z(t_line *line)
{
	int prev_x;
	int prev_y;

	prev_x = line->x1;
	prev_y = line->y1;
	line->x1 = prev_x * cos(line->rotatez) + prev_y * sin(line->rotatez);
	line->y1 = -prev_x * sin(line->rotatez) + prev_y * cos(line->rotatez);
	prev_x = line->x2;
	prev_y = line->y2;
	line->x2 = prev_x * cos(line->rotatez) + prev_y * sin(line->rotatez);
	line->y2 = -prev_x * sin(line->rotatez) + prev_y * cos(line->rotatez);
}
