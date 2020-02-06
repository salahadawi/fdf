/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:41:33 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/06 14:06:01 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

#define WINDOW_HEIGHT 1000
#define WINDOW_WIDTH 1500

typedef struct  s_map
{
	int			**map;
	int			cols;
	int			rows;

}				t_map;


typedef struct s_line
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			color;
	int			zoom;
}				t_line;

typedef	struct	s_mlx
{
	void		*init;
	void		*window;
	void		*image_ptr;
	char		*image;
	int			bpp;
	int			size_line;
	int			endian;
	t_map		*s_map;
	t_line		*line;

}				t_mlx;

void	print_map(t_map *s_map);
void	store_map(char *file, t_map *s_map);
void	malloc_extra_row(t_map *s_map);
void	store_map_line(char *line, t_map *s_map);
int		count_ints(char *line);
void	check_line(char *line);
void	handle_error(int code);
int		check_key(int key, void *param);
void	draw_line(t_line *line, t_mlx *mlx);
int		handle_drawing(void *param);
