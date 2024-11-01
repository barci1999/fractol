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
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./minilibx-linux
LIBS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

SRCS = main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
