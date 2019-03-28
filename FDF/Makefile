# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 14:45:55 by sgusache          #+#    #+#              #
#    Updated: 2019/03/27 22:33:28 by sgusache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC		= main.c \
		key_press.c \
		drawing.c \
		read_map.c\
		utils.c \

CC	= cc -g
CFLAGS	= -Wall -Wextra -Werror -o
PATH	= -I /usr/local/include
LIBFT	= get_next_line/libft/libft.a
GET_NEXT	= get_next_line/get_next_line.c
MLX	= ./minilibx_macos/libmlx.a
MLX_LIB	= -L /usr/local/lib/
MLX_LIB_PATH	= -I./minilibx_macos
FRAEM	= -framework OpenGL -framework AppKit

all:
	$(CC) $(CFLAGS) $(NAME) $(PATH) $(SRC) $(LIBFT) $(GET_NEXT) $(MLX) $(MLX_LIB) $(MLX_LIB_PATH) $(FRAEM)
clean:
	rm -rf fdf
fclean: clean
	rm -rf $(NAME)
re: fclean all

#cc -g -I /usr/local/include main.c key_press.c drawing.c read_map.c get_next_line/libft/libft.a get_next_line/get_next_line.c ./minilibx_macos/libmlx.a -L /usr/local/lib/ -I./minilibx_macos -framework OpenGL -framework AppKit
