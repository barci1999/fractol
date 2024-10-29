/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-29 11:27:19 by pablalva          #+#    #+#             */
/*   Updated: 2024-10-29 11:27:19 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_data {
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    char *img_data;
	int size_x;
	int size_y;
    int width;
    int height;
    int bits_per_pixel;
    int line_length;
	int running;
	int color_state;
	int current_color;
    int endian;
} t_data;

#endif