/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:41:33 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/19 17:03:42 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"
# include <math.h>
# include <X11/X.h>

# define WIN_HEIGHT	1000
# define WIN_WIDTH	1500

typedef struct		s_map
{
	char			*name;
	int				**map;
	int				*mapxy;
	int				cols;
	int				rows;
	int				biggestz;

}					t_map;

typedef struct		s_line
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				z1;
	int				z2;
	int				color;
	double			zoom;
	int				autooffset;
	int				offsetx;
	int				offsety;
	int				iso;
	double			pitch;
	double			rotatex;
	double			rotatey;
	double			rotatez;
	int				colors;
	int				idle;

}					t_line;

typedef	struct		s_mlx
{
	void			*init;
	void			*window;
	void			*image_ptr;
	char			*image;
	int				bpp;
	int				size_line;
	int				endian;
	int				mouse1;
	int				mouse2;
	int				mousex;
	int				mousey;
	int				gui;
	t_map			*s_map;
	t_line			*line;

}					t_mlx;

void				check_360(t_line *line);
int					handle_idle(t_mlx *mlx);
void				handle_offset(int dir, t_mlx *mlx);
void				handle_pitch(int key, t_mlx *mlx);
void				handle_rotatex(int key, t_mlx *mlx);
void				handle_rotatey(int key, t_mlx *mlx);
void				handle_rotatez(int key, t_mlx *mlx);
void				check_rotation(int key, t_mlx *mlx);
void				handle_reset(t_mlx *mlx);
void				handle_iso(t_mlx *mlx);
int					check_key(int key, void *param);
int					mouse_press(int key, int x, int y, void *param);
int					mouse_release(int key, int x, int y, void *param);
void				handle_mouse1_move(int x, int y, t_mlx *mlx);
void				handle_mouse2_move(int x, int y, t_mlx *mlx);
int					mouse_move(int x, int y, void *param);
void				handle_error(int code);
void				draw_pixel(int x, int y, int color, t_mlx *mlx);
void				plot_line_low(t_line *line, t_mlx *mlx);
void				plot_line_high(t_line *line, t_mlx *mlx);
void				swap_points(t_line *line);
void				plot_line(t_line *line, t_mlx *mlx);
void				handle_color_high(t_line *line, double d);
void				handle_color_low(t_line *line, double d);
void				handle_simple_color(t_line *line);
void				handle_color(t_line *line, t_mlx *mlx);
void				handle_transform(t_line *line);
void				draw_line(t_line *line, t_mlx *mlx);
void				transform_iso(t_line *line);
void				rotate_x(t_line *line);
void				rotate_y(t_line *line);
void				rotate_z(t_line *line);
void				handle_line_draw(int xy[4], t_line *line, t_mlx *mlx);
void				draw_map(t_line *line, t_mlx *mlx);
void				map_to_coordinates(t_map *s_map);
void				draw_background(t_mlx *mlx);
void				draw_gui_double(t_mlx *mlx, int x, int y, double d);
void				mlxstr(t_mlx *mlx, int x, int y, char *str);
void				draw_gui(t_mlx *mlx);
int					handle_drawing(void *param);
void				initialize_line(t_line *line, t_mlx *mlx);
void				handle_graphics(t_map *s_map);
void				store_map(char *file, t_map *s_map);
void				check_count(int count, t_map *s_map);
void				store_map_line(char *line, t_map *s_map);
void				malloc_extra_row(t_map *s_map);
void				check_line(char *line);
int					bigger_than_int(char *line);
int					count_ints(char *line, t_map *s_map);

#endif
