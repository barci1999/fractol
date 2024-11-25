# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: pablalva <pablalva@student.42madrid.com>   #+#  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2024-10-28 10:44:11 by pablalva          #+#    #+#             #
#   Updated: 2024-10-28 10:44:11 by pablalva         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = fractol_github
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include -I./minilibx-linux -I libft  -I printf
MLX_DIR = ./minilibx-linux
LIBFT_DIR = ./libft
PRINTF_DIR = ./printf
LIBS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -L libft -lft -L printf -lftprintf -no-pie

SRCS = main.c src/mandelbrot.c src/utils_win_control.c src/utils_var.c src/utils_mouse.c\
		src/utils_key.c src/utils_color.c src/julia.c src/burningship.c
OBJS = $(SRCS:.c=.o)

all:  $(NAME)


$(NAME): $(OBJS)
	make -s -C printf
	make -s -C libft 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	make -C printf fclean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
