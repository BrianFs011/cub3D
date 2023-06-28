/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:08:36 by briferre          #+#    #+#             */
/*   Updated: 2023/06/28 13:53:42 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	load_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			my_mlx_pixel_put(data, j, i, color);
	}
}

void	draw_rect(t_data *data, int *p, int color)
{
	int	width;
	int	height;
	int	i;
	int	j;

	width = 100;
	height = 100;
	(void)height;
	i = p[X];
	while (i < p[X] + width)
	{
		j = p[Y];
		while (j < p[Y] + height)
		{
			my_mlx_pixel_put(data, i, j, color);
			j++;
		}
		i++;
	}
	free(p);
}
