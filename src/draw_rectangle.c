/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:08:36 by briferre          #+#    #+#             */
/*   Updated: 2023/07/12 07:33:48 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
