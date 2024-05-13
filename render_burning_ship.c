/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_burning_ship.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:36:42 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/04/23 17:27:10 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	handel_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	color = 0;
	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = (scale(x, 0, -2, 2) * fractal->zoom) + fractal->shift_x;
	c.y = (scale(y, 0, -2, 2) * fractal->zoom) + fractal->shift_y;
	while (++i < fractal->iterations_max && !(z.x * z.x + z.y * z.y >= 4))
	{
		z.temp = z.x * z.x - z.y * z.y + c.x;
		z.y = fabs(2.0 * z.y * z.x) + c.y;
		z.x = fabs(z.temp);
	}
	if (i == fractal->iterations_max)
		pixel_put(x, y, &fractal->img, color);
	else
	{
		color = scale(i, 0, fractal->color, BLACK);
		pixel_put(x, y, &fractal->img, color);
	}
}

void	fractal_render_burning_ship(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			handel_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
