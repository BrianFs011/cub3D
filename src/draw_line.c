/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:10:06 by briferre          #+#    #+#             */
/*   Updated: 2023/09/10 19:42:55 by sde-cama         ###   ########.fr       */
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

int	get_texture_pixel(t_mlx *mlx, int x, int y, enum e_cardinal pos)
{
	if (pos == so)
		return (mlx->texture.so[y][x]);
	else if (pos == we)
		return (mlx->texture.we[y][x]);
	else if (pos == ea)
		return (mlx->texture.ea[y][x]);
	return (mlx->texture.no[y][x]);
}

void	draw_line_texture(t_data *data, int *p, t_mlx *mlx)
{
	int		texture;
	double	x_texture;
	double	y_texture;
	double	y_texture_step;

	x_texture = wall_texture_x(mlx);
	y_texture_step = TEXHEIGHT;
	y_texture_step /= (float)(HEIGHT / mlx->camera.perpendicular_dist);
	while (p[2] < p[3])
	{
		texture = get_texture_pixel(mlx,
				x_texture,
				y_texture,
				mlx->camera.cardinal);
		my_mlx_pixel_put(data, p[0], p[2], texture);
		p[2]++;
		y_texture += y_texture_step;
	}
	free(p);
}
