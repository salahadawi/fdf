# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 16:18:52 by sadawi            #+#    #+#              #
#    Updated: 2020/02/19 16:55:34 by sadawi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
SRCS=srcs/check_input.c srcs/handle_color.c srcs/handle_gui.c \
srcs/handle_transformation.c srcs/print_map.c srcs/check_key.c \
srcs/handle_error.c srcs/handle_mouse.c srcs/main.c srcs/store_input.c \
srcs/draw_map.c srcs/handle_graphics.c srcs/handle_rotation.c srcs/plot_line.c \
srcs/handle_keys.c
OBJS=$(notdir $(SRCS:.c=.o))
INCLUDES= -I includes -I libft
FLAGS=-Wall -Wextra -Werror
MLX=-I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL \
-framework Appkit
RUN_LIB=make -C libft/ fclean && make -C libft/

all: $(NAME)

$(NAME):
	@$(RUN_LIB)
	@echo Compiling $(NAME)...
	@gcc $(FLAGS) $(INCLUDES) -c $(SRCS)
	@gcc $(FLAGS) $(INCLUDES) $(MLX) -o $(NAME) $(OBJS) libft/libft.a
	@echo $(NAME) compiled succesfully!

clean:
	@/bin/rm -f $(OBJS)
	@make -C libft/ clean
	@echo Clean successful!

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean
	@echo Fclean successful!

re: fclean all
