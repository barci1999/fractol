/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 13:47:27 by pablalva          #+#    #+#             */
/*   Updated: 2024-10-28 13:47:27 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	close_win(t_data *data)
{
	if (data->img_ptr)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		data->img_ptr = NULL;
	}
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
	exit(0);
}

int	refresh(t_data *data)
{
	if (data->running && ft_strncmp(data->fractal_type, "Burningship", 11) == 0)
	{
		draw_burning(data);
		data->running = 0;
	}
	if (data->running && ft_strncmp(data->fractal_type, "Mandelbrot", 10) == 0)
	{
		draw_mandel(data);
		data->running = 0;
	}
	if (data->running && ft_strncmp(data->fractal_type, "Julia", 5) == 0)
	{
		draw_julia(data);
		data->running = 0;
	}
	return (0);
}
