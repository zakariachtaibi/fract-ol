/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:13:38 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/04/22 17:58:02 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_mandelbrot(char **av)
{
	t_fractal	fractal;

	fractal.set = 1;
	fractal.name = av[1];
	fractal_init(&fractal);
	fractal_render_mandelbrot(&fractal);
	mlx_loop(fractal.mlx_connection);
}

void	handle_julia(char **av, int ac)
{
	t_fractal	fractal;

	fractal.set = 2;
	fractal.name = av[1];
	if (ac == 2)
	{
		fractal.c_r = -0.4;
		fractal.c_i = 0.6;
	}
	else
	{
		fractal.c_r = ft_atod(av[2], &fractal);
		fractal.c_i = ft_atod(av[3], &fractal);
	}
	fractal_init(&fractal);
	fractal_render_julia(&fractal);
	mlx_loop(fractal.mlx_connection);
}

void	handle_burning_ship(char **av)
{
	t_fractal	fractal;

	fractal.set = 3;
	fractal.name = av[1];
	fractal_init(&fractal);
	fractal_render_burning_ship(&fractal);
	mlx_loop(fractal.mlx_connection);
}

int	main(int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		handle_mandelbrot(av);
	else if ((ac == 4 || ac == 2) && !ft_strncmp(av[1], "julia", 5))
	{
		handle_julia(av, ac);
	}
	else if (ac == 2 && !ft_strncmp(av[1], "burning_ship", 12))
		handle_burning_ship(av);
	else
	{
		write(1, "please enter mandelbrot or julia or burning_ship\n", 50);
		exit(1);
	}
	return (0);
}
