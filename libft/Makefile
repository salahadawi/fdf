# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 18:05:28 by sadawi            #+#    #+#              #
#    Updated: 2020/02/19 16:54:43 by sadawi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
ft_putlst.c ft_lstevery.c ft_strfill.c ft_strsplitlst.c ft_swap.c ft_longlen.c \
ft_foreach.c ft_putlong.c ft_ulonglen.c ft_putulong.c ft_itoa_base.c \
ft_itoa_base_low.c ft_itoa_base_ul.c ft_itoa_base_ul_low.c ft_putdouble.c \
ft_itoa_double.c ft_chartostr.c ft_printf.c handle_digit_datatypes.c \
handle_string_datatypes.c handle_flags.c handle_format_flags.c handle_width.c \
handle_char.c ft_atoilong.c get_next_line.c ft_strjoinfree.c ft_isdigit_neg.c \
ft_strcatfree.c

OBJS = *.o

all: $(NAME)

$(NAME): libft.h
	@echo Compiling $(NAME)...
	@gcc -c -Wall -Werror -Wextra $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@echo $(NAME) compiled succesfully!

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
