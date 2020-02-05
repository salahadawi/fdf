/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:41:33 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/04 14:41:35 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

typedef	struct	s_mlx
{
	void        *init;
    void        *window;
    int         height;
    int         width;
    int         x;
    int         y;

}				t_mlx;

typedef struct  s_map    
{
    int         **map;
    int         cols;
    int         rows;

}               t_map;

void	print_map(t_map *s_map);
void	store_map(char *file, t_map *s_map);
void	malloc_extra_row(t_map *s_map);
void	store_map_line(char *line, t_map *s_map);
int		count_ints(char *line);
void	check_line(char *line);
void	handle_error(int code);
int		check_key(int key, void *param);
int		draw_line(int dir, void *param);