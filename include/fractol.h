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
# define FRACTOL_H

# include "mlx.h"
# include "mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <libft.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ft_printf.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		max_iter;
	int		height;
	int		width;
	int		x;
	int		y;
	double	c_re;
	double	c_img;
	int		color;
	int		size_x;
	int		size_y;
	double	center_re;
	double	center_img;
	double	zoom_factor;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	int		iter;
	int		*pixels;
	int		bits_per_pixel;
	int		line_length;
	int		running;
	int		color_state;
	int		endian;
	int		color_set;
	double	z_img;
	double	z_re;
	char	*fractal_type;
}			t_data;

void		var_init(t_data *data);
int			close_win(t_data *data);
int			refresh(t_data *data);
int			mouse_control(int button, int x, int y, void *param);
int			keys_contol(int keycode, t_data *data);
void		draw_mandel(t_data *data);
void		draw_julia(t_data *data);
void		draw_burning(t_data *data);
int			color_select(t_data *data);

#endif