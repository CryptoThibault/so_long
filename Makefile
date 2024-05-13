# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 11:47:38 by tchalaou          #+#    #+#              #
#    Updated: 2024/05/07 17:21:40 by tchalaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIB = libft
FILES =	srcs/main.c \
	srcs/check_input.c \
	srcs/perror_exit.c \
	srcs/free_data.c \
	srcs/free_array.c \
	srcs/create_map.c \
	srcs/get_line_count.c \
	srcs/check_map.c \
	srcs/get_position.c \
	srcs/get_collect_count.c \
	srcs/dup_array.c \
	srcs/flood_fill.c \
	srcs/so_long.c \
	srcs/load_images.c \
	srcs/draw_map.c \
	srcs/update_map.c \
	srcs/handle_keypress.c \
	srcs/on_destroy.c
FLAGS = -Wall -Wextra -Werror
MLX = minilibx-linux
MLX_FLAGS = -lX11 -lXext -lmlx -Lminilibx-linux

$(NAME): $(LIB)/$(LIB).a $(MLX)
	cc $(FLAGS) -o $@ $(FILES) $(LIB)/$(LIB).a $(MLX_FLAGS)
all: $(NAME)

clean:
	rm -f *.out
fclean: clean
	rm -f $(NAME)
re: fclean all

$(LIB)/$(LIB).a:
	make -C $(LIB)

$(MLX): mlx

mlx:
	make -C $(MLX)
