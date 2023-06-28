/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:10:06 by briferre          #+#    #+#             */
/*   Updated: 2023/06/22 17:31:20 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_line(t_data *data, int *p, int color)
{
	int	delta[2];
	int	error[2];

	delta[X] = ternary_int(p[1] - p[0] >= 0, p[1] - p[0], (p[1] - p[0]) * -1);
	delta[Y] = ternary_int(p[3] - p[2] >= 0, p[3] - p[2], (p[3] - p[2]) * -1);
	error[0] = delta[X] - delta[Y];
	while (p[0] != p[1] || p[2] != p[3])
	{
		my_mlx_pixel_put(data, p[0], p[2], color);
		error[1] = 2 * error[0];
		if (error[1] > -delta[Y])
		{
				error[0] -= delta[Y];
				p[0] += ternary_int(p[0] < p[1], 1, -1);
		}
		if (error[1] < delta[X])
		{
				error[0] += delta[X];
				p[2] += ternary_int(p[2] < p[3], 1, -1);
		}
	}
	free(p);
}
