/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:23:22 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/04/22 17:27:12 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_fractal *fractal)
{
	fractal->iterations_max = 50;
	fractal->escape_val = 4;
	fractal->zoom = 1.0;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->color = BLUE;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, 17, 0, close_handler, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, 02, 1L << 0, key_handler, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = NULL;
	fractal->mlx_window = NULL;
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		exit(1);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WINDOW_WIDTH,
			WINDOW_HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		free(fractal->mlx_connection);
		exit(1);
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		exit(1);
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	data_init(fractal);
	events_init(fractal);
}
