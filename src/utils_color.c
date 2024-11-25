/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-18 19:56:03 by pablalva          #+#    #+#             */
/*   Updated: 2024-11-18 19:56:03 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static int	color_org(t_data *data)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	t = (double)data->iter / (double)data->max_iter;
	if (data->iter == data->max_iter)
		return (0x000000);
	red = (int)((sin(t * M_PI * 2) * 0.5 + 0.5) * 255);
	green = (int)((sin((t + 0.33) * M_PI * 2) * 0.5 + 0.5) * 255);
	blue = (int)((sin((t + 0.66) * M_PI * 2) * 0.5 + 0.5) * 255);
	return ((red << 16) | (green << 8) | blue);
}

static int	color_variation(t_data *data)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	t = (double)data->iter / (double)data->max_iter;
	if (data->iter == data->max_iter)
		return (0x000000);
	red = (int)((sin(t * M_PI * 3) * 0.5 + 0.5) * 255);
	green = (int)((sin((t + 0.5) * M_PI * 2) * 0.5 + 0.5) * 255);
	blue = (int)((sin((t + 1.0) * M_PI * 2) * 0.5 + 0.5) * 255);
	return ((red << 16) | (green << 8) | blue);
}

int	color_select(t_data *data)
{
	if (data->color_set == 0)
		return (color_org(data));
	return (color_variation(data));
}
