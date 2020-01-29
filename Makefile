#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 12:10:11 by sadawi            #+#    #+#              #
#    Updated: 2020/01/29 15:14:00 by sadawi           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=fdf
SRCS=*.c
OBJS=$(notdir $(SRCS:.c=.o))
FLAGS=-Wall -Wextra -Werror
MLX=-I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL \
-framework Appkit
RUN_LIB=make -C libft/ fclean && make -C libft/

all: $(NAME)

$(NAME):
	@$(RUN_LIB)
	gcc $(FLAGS) -c $(SRCS)
	gcc $(FLAGS) $(MLX) -o $(NAME) $(OBJS) libft/libft.a

clean:
	/bin/rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
