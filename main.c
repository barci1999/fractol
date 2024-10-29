/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 10:39:54 by pablalva          #+#    #+#             */
/*   Updated: 2024-10-28 10:39:54 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	cerrar_ventana(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	exit(0);
}
void	fill_reverse_win(void *mlx_ptr, void *win_ptr, int color)
{
	int	x;
	int	y;

	x = 800;
	y = 800;
	while (y > 0)
	{
		x = 800;
		while (x > 0)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			x--;
		}
		y--;
	}
}
void	fill_win(void *mlx_ptr, void *win_ptr, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			x++;
		}
		y++;
	}
}
int	key_press_space(int key, t_data *data)
{
	if (key == ' ')
		data->running = !data->running;
	else if (key == 'o')
	{
		data->current_color = 0xFF69B4;
		data->running = 0;
	}
	return (0);
}
int resfresh(t_data *data) {
    if (data->running)
	{
        if (data->color_state == 0)
            data->current_color = 0xFF0000; // Rojo
        else if (data->color_state == 1) 
            data->current_color = 0x00FF00; // Verde
        else
            data->current_color = 0x0000FF; // Azul
        fill_win(data->mlx_ptr, data->win_ptr, data->current_color);
        data->color_state = (data->color_state + 1) % 3;
    }
	else 
        fill_win(data->mlx_ptr, data->win_ptr, data->current_color);
    usleep(50000);
    return (0);
}

int	main(void)
{
	t_data data;

	data.size_x = 800;
	data.size_y = 800;
	data.running = 1;
	data.color_state = 0;
	data.current_color = 0xFF0000;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.size_x, data.size_y,
			"hola");
	if (data.win_ptr == NULL)
		return (1);
	mlx_key_hook(data.win_ptr, key_press_space, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &cerrar_ventana,
		&data);
	mlx_loop_hook(data.mlx_ptr, &resfresh, &data);

	mlx_loop(data.mlx_ptr);
	return (0);
}