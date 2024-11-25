/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 11:55:03 by pablalva          #+#    #+#             */
/*   Updated: 2024-11-17 11:55:03 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	arrow_control(int keycode, t_data *data)
{
	double	move;

	move = 0.1;
	if (keycode == XK_Up)
	{
		data->y_max -= move;
		data->y_min -= move;
	}
	else if (keycode == XK_Down)
	{
		data->y_max += move;
		data->y_min += move;
	}
	else if (keycode == XK_Right)
	{
		data->x_max += move;
		data->x_min += move;
	}
	else if (keycode == XK_Left)
	{
		data->x_max -= move;
		data->x_min -= move;
	}
	data->running = 1;
	return (0);
}

int	esc_control(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_win(data);
	data->running = 1;
	return (0);
}

int	c_color_control(int keycode, t_data *data)
{
	if (keycode == XK_c && ft_strncmp(data->fractal_type, "Burningship",
			11) == 0)
	{
		data->color_set = (data->color_set + 1) % 2;
		draw_burning(data);
	}
	if (keycode == XK_c && ft_strncmp(data->fractal_type, "Mandelbrot",
			10) == 0)
	{
		data->color_set = (data->color_set + 1) % 2;
		draw_mandel(data);
	}
	if (keycode == XK_c && ft_strncmp(data->fractal_type, "Julia", 5) == 0)
	{
		data->color_set = (data->color_set + 1) % 2;
		draw_julia(data);
	}
	data->running = 1;
	return (0);
}

int	keys_contol(int keycode, t_data *data)
{
	if (keycode == XK_c)
		c_color_control(keycode, data);
	if (keycode == XK_Escape)
		esc_control(keycode, data);
	else
		arrow_control(keycode, data);
	data->running = 1;
	return (0);
}
