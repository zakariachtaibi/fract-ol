/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:13:36 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/04/29 15:39:32 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WINDOW_WIDTH 800
# define BLACK 0x000000
# define BOLD 0xFCBE11
# define BLUE 0x5BBCFF
# define WHITE 0xFFFFFF
# define WINDOW_HEIGHT 800

typedef struct s_complex
{
	double	x;
	double	y;
	double	temp;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_atod
{
	double	result;
	int		i;
	double	decimal_part;
	double	decimal_multiplier;
	int		sign;

}			t_atod;

typedef struct s_fractal
{
	t_atod	ad;
	int		set;
	double	c_r;
	double	c_i;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	char	*name;
	int		iterations_max;
	int		escape_val;
	int		color;
	double	zoom;
	double	shift_x;
	double	shift_y;
}			t_fractal;

void		fractal_init(t_fractal *fractal);
void		fractal_render_julia(t_fractal *fractal);
void		fractal_render_mandelbrot(t_fractal *fractal);
void		fractal_render_burning_ship(t_fractal *fractal);

double		scale(int value, int oldmin, int newmin, int newmax);

t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_burning(t_complex z);
double		ft_atod(const char *nptr, t_fractal *fractol);
t_complex	square(t_complex z);

int			key_handler(int keycode, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);

double		ft_atod(const char *nptr, t_fractal *f);
int			ft_isdigit(int c);
int			ft_strcmp(const char *s1, const char *s2);
void		check_julia(char **av, int index);

#endif