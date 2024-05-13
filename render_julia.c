/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:10:04 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/04/23 17:21:24 by zchtaibi         ###   ########.fr       */
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

	i = 0;
	z.x = (scale(x, 0, -2, 2) * fractal->zoom) + fractal->shift_x;
	z.y = (scale(y, 0, 2, -2) * fractal->zoom)
		+ fractal->shift_y;
	c.x = fractal->c_r;
	c.y = fractal->c_i;
	while (i < fractal->iterations_max)
	{
		z = sum_complex(square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_val)
		{
			color = scale(i, 0, fractal->color, BLUE);
			pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	pixel_put(x, y, &fractal->img, BLACK);
}

void	fractal_render_julia(t_fractal *fractal)
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
