/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:10:06 by briferre          #+#    #+#             */
/*   Updated: 2023/08/14 16:49:53 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_texture_pixel(t_mlx *mlx, int x, int y, int pos);

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

void	draw_line_texture(t_data *data, int *p, t_mlx *mlx)
{
	int		delta[2];
	int		error[2];
	int		texture;
	double	x_texture;
	double	y_texture;
	double	y_texture_step;

	delta[X] = ternary_int(p[1] - p[0] >= 0, p[1] - p[0], (p[1] - p[0]) * -1);
	delta[Y] = ternary_int(p[3] - p[2] >= 0, p[3] - p[2], (p[3] - p[2]) * -1);
	error[0] = delta[X] - delta[Y];
	y_texture = 0;
	x_texture = (int) (p[0]/3) % texWidth;
	y_texture_step = texHeight / (float) (HEIGHT / mlx->camera.perpendicular_dist);
	while (p[0] != p[1] || p[2] != p[3])
	{
		texture = get_texture_pixel(mlx, x_texture, y_texture, mlx->camera.orientation);
		my_mlx_pixel_put(data, p[0], p[2], texture);
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
		y_texture += y_texture_step;
	}
	free(p);
}

int	get_texture_pixel(t_mlx *mlx, int x, int y, int pos)
{
	if (pos == 1)
		return (mlx->textureSO[y][x]);
	else if (pos == 2)
		return (mlx->textureWE[y][x]);
	else if (pos == 3)
		return (mlx->textureEA[y][x]);
	return (mlx->textureNO[y][x]);
}
