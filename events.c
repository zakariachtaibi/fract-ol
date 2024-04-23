/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:18:07 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/04/22 18:00:34 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define XK_ESCAPE 53
#define XK_LEFT 124
#define XK_UP 126
#define XK_RIGHT 123
#define XK_DOWN 125
#define XK_PLUS 69
#define XK_MINUS 78

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	free(fractal->mlx_connection);
	exit(0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 5)
		fractal->zoom *= 0.95;
	else if (button == 4)
		fractal->zoom *= 1.05;
	if (fractal->set == 1)
		fractal_render_mandelbrot(fractal);
	else if (fractal->set == 2)
		fractal_render_julia(fractal);
	else if (fractal->set == 3)
		fractal_render_burning_ship(fractal);
	return (0);
}

static void	handel_pan(int keycode, t_fractal *fractal)
{
	if (keycode == XK_LEFT)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keycode == XK_RIGHT)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keycode == XK_DOWN)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keycode == XK_UP)
		fractal->shift_y -= (0.5 * fractal->zoom);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == 49)
		fractal->color += 100000;
	else if (keycode == XK_ESCAPE)
		close_handler(fractal);
	else if (keycode == XK_PLUS)
		fractal->iterations_max += 42;
	else if (keycode == XK_MINUS)
		fractal->iterations_max -= 42;
	else if (keycode == 18)
		fractal->iterations_max += 10;
	else if (keycode == 19)
		fractal->iterations_max -= 10;
	else
		handel_pan(keycode, fractal);
	if (fractal->set == 1)
		fractal_render_mandelbrot(fractal);
	else if (fractal->set == 2)
		fractal_render_julia(fractal);
	else if (fractal->set == 3)
		fractal_render_burning_ship(fractal);
	return (0);
}
