/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:35:23 by zchtaibi          #+#    #+#             */
/*   Updated: 2024/04/29 15:48:12 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_invalid_input(char **av, int index, int i, int dot_count)
{
	if ((av[index][i] < '0' || av[index][i] > '9') && av[index][i] != '.')
	{
		write(1, "Invalid argument: non-digit found\n", 35);
		exit(EXIT_FAILURE);
	}
	if (av[index][i] == '.')
	{
		if (++dot_count > 1)
			exit(EXIT_FAILURE);
	}
}

void	check_julia(char **av, int index)
{
	int	i;
	int	dot_count;

	dot_count = 0;
	i = 0;
	while (av[index][i] == ' ')
		i++;
	if (av[index][i] == '-' || av[index][i] == '+')
		i++;
	while (av[index][i])
	{
		if ((av[index][i] == '.' && !av[index][i++]) || (av[index][i] == '.'
				&& av[index][i++] == '.'))
			exit(EXIT_FAILURE);
		handle_invalid_input(av, index, i, dot_count);
		i++;
	}
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
