/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:31:23 by briferre          #+#    #+#             */
/*   Updated: 2023/06/29 18:41:41 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_circle(t_data *data, int *p, int r, int color)
{
	int	i;
	int	j;
	int	theta;

	i = p[X];
	j = p[Y];
	theta = -1;
	while (++theta < 360)
	{
		draw_line(data, vector_points(p[X], p[X] + cos(theta) * r,
				p[Y] + sin(theta) * r, p[Y] + sin(theta) * r),
			color);
		my_mlx_pixel_put(data, i + cos(theta) * r, j + sin(theta) * r, color);
	}
	free(p);
}
