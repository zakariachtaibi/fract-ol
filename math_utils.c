/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:54:15 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/04/22 17:57:17 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(int value, int oldmin, int newmin, int newmax)
{
	double	new;

	new = (((double)(value - oldmin) / (800 - oldmin)) * (newmax - newmin))
		+ newmin;
	return (new);
}

t_complex	square(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = (2 * z.y * z.x);
	return (result);
}

t_complex	square_burning(t_complex z)
{
	t_complex	result;

	result.x = fabs(2 * z.y * z.x);
	result.y = ((z.x * z.x) - (z.y * z.y));
	return (result);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

double	ft_atod(const char *nptr, t_fractal *f)
{
	f->ad.result = 0.0;
	f->ad.i = 0;
	f->ad.sign = 1;
	f->ad.decimal_part = 0.0;
	f->ad.decimal_multiplier = 0.1;
	while (nptr[f->ad.i] == ' ')
		f->ad.i++;
	if (nptr[f->ad.i] == '+' || nptr[f->ad.i] == '-')
		if (nptr[f->ad.i++] == '-')
			f->ad.sign *= -1;
	if (!nptr[f->ad.i])
		exit(EXIT_FAILURE);
	while (ft_isdigit(nptr[f->ad.i]))
		f->ad.result = f->ad.result * 10 + (nptr[f->ad.i++] - '0');
	if (nptr[f->ad.i] == '.')
	{
		f->ad.i++;
		while (ft_isdigit(nptr[f->ad.i]))
		{
			f->ad.decimal_part = f->ad.decimal_part + (nptr[f->ad.i++] - '0')
				* f->ad.decimal_multiplier;
			f->ad.decimal_multiplier *= 0.1;
		}
	}
	return ((f->ad.result + f->ad.decimal_part) * f->ad.sign);
}
