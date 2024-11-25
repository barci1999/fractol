/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 10:31:14 by pablalva          #+#    #+#             */
/*   Updated: 2024-11-17 10:31:14 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	var_init(t_data *data)
{
	data->color = 0xff0000;
	data->max_iter = 75;

	data->zoom_factor = 1.0;
	data->width = 800;
	data->height = 800;
	data->x_min = -2.0;
	data->x_max = 2.0;
	data->y_min = -2.0;
	data->y_max = 2.0;
	data->color_set = 0;
	data->z_img = 0.0;
	data->z_re = 0.0;
	data->fractal_type = NULL;
}
