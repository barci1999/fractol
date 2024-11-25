/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-19 16:11:38 by pablalva          #+#    #+#             */
/*   Updated: 2024-11-19 16:11:38 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static int	math_burning(double c_re, double c_img, int max_iter, t_data *data)
{
	int		iter;
	double	temp;

	data->z_re = 0.0;
	data->z_img = 0.0;
	temp = 0.0;
	iter = 0;
	while (data->z_re * data->z_re + data->z_img * data->z_img <= 4.0
		&& iter < max_iter)
	{
		temp = fabs(data->z_re) * fabs(data->z_re) - fabs(data->z_img)
			* fabs(data->z_img) + c_re;
		data->z_img = 2.0 * fabs(data->z_re) * fabs(data->z_img) + c_img;
		data->z_re = temp;
		iter++;
	}
	if (iter < 0)
		iter = 0;
	return (iter);
}

void	draw_burning(t_data *data)
{
	int		x;
	int		y;
	double	c_re;
	double	c_img;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			c_re = data->x_min + (x / (double)data->width) * (data->x_max
					- data->x_min);
			c_img = data->y_min + (y / (double)data->height) * (data->y_max
					- data->y_min);
			data->iter = math_burning(c_re, c_img, data->max_iter, data);
			data->color = color_select(data);
			data->pixels[y * data->width + x] = data->color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
