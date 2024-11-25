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

static int	fun_burning(char *argv[])
{
	t_data	data;

	var_init(&data);
	data.fractal_type = "Burningship";
	data.width = ft_atoi(argv[2]);
	data.height = ft_atoi(argv[3]);
	data.size_x = data.width;
	data.size_y = data.height;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.size_x, data.size_y,
			"Burningship");
	data.img_ptr = mlx_new_image(data.mlx_ptr, data.width, data.height);
	data.pixels = (int *)mlx_get_data_addr(data.img_ptr, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	mlx_hook(data.win_ptr, 17, 0, close_win, &data);
	mlx_mouse_hook(data.win_ptr, mouse_control, &data);
	mlx_key_hook(data.win_ptr, keys_contol, &data);
	mlx_loop_hook(data.mlx_ptr, &refresh, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

static int	fun_julia(char *argv[])
{
	t_data	data;

	var_init(&data);
	data.fractal_type = "Julia";
	data.width = ft_atoi(argv[2]);
	data.height = ft_atoi(argv[3]);
	data.c_re = ft_atof(argv[4]);
	data.c_img = ft_atof(argv[5]);
	data.size_x = data.width;
	data.size_y = data.height;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.size_x, data.size_y,
			"julia");
	data.img_ptr = mlx_new_image(data.mlx_ptr, data.width, data.height);
	data.pixels = (int *)mlx_get_data_addr(data.img_ptr, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	mlx_hook(data.win_ptr, 17, 0, close_win, &data);
	mlx_mouse_hook(data.win_ptr, mouse_control, &data);
	mlx_key_hook(data.win_ptr, keys_contol, &data);
	mlx_loop_hook(data.mlx_ptr, &refresh, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

static int	fun_mandel(char *argv[])
{
	t_data	data;

	var_init(&data);
	data.fractal_type = "Mandelbrot";
	data.width = ft_atoi(argv[2]);
	data.height = ft_atoi(argv[3]);
	data.size_x = data.width;
	data.size_y = data.height;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.size_x, data.size_y,
			"Mandelbrot");
	data.img_ptr = mlx_new_image(data.mlx_ptr, data.width, data.height);
	data.pixels = (int *)mlx_get_data_addr(data.img_ptr, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	mlx_hook(data.win_ptr, 17, 0, close_win, &data);
	mlx_mouse_hook(data.win_ptr, mouse_control, &data);
	mlx_key_hook(data.win_ptr, keys_contol, &data);
	mlx_loop_hook(data.mlx_ptr, &refresh, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

static void	fun_error(void)
{
	ft_printf("\n Error in parameters:\n");
	ft_printf("\n Please insert parameters like this:\n");
	ft_printf("\n	-Mandelbrot (height window) (width window).\n");
	ft_printf("\n	-Burningship (height window) (width window).\n");
	ft_printf("\n	-Julia (height window) (width window)"
		" (real number) (imaginari number).\n");
	ft_printf("\n Thanks. :)\n\n");
}

int	main(int argc, char *argv[])
{
	if (argc != 4 && argc != 6)
	{
		fun_error();
		return (1);
	}
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0 && ft_str_isdigit(argv[2])
		&& ft_str_isdigit(argv[3]))
		fun_mandel(argv);
	if (ft_strncmp(argv[1], "Julia", 5) == 0 && ft_str_isdigit(argv[2])
		&& ft_str_isdigit(argv[3]) && ft_str_is_dec(argv[4])
		&& ft_str_is_dec(argv[5]))
		fun_julia(argv);
	if (ft_strncmp(argv[1], "Burningship", 11) == 0 && ft_str_isdigit(argv[2])
		&& ft_str_isdigit(argv[3]))
		fun_burning(argv);
	else
		fun_error();
	return (0);
}
