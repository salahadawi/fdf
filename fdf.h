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
