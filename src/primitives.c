/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:19:19 by briferre          #+#    #+#             */
/*   Updated: 2023/08/14 15:00:07 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	y = ternary_int(y > HEIGHT, HEIGHT, y);
	y = ternary_int(y < 0, 0, y);
	x = ternary_int(x > WIDTH, WIDTH, x);
	x = ternary_int(x < 0, 0, x);
	dst = data->addr
		+ ((HEIGHT - y) * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	load_background(t_data *data, int floor, int ceil)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j <= HEIGHT)
		{
			if (j > HEIGHT / 2)
				my_mlx_pixel_put(data, i, j, ceil);
			else
				my_mlx_pixel_put(data, i, j, floor);
		}
	}
}
