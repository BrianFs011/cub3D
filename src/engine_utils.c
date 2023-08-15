/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:55:52 by briferre          #+#    #+#             */
/*   Updated: 2023/07/18 20:57:18 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	delta_dist(t_mlx *mlx)
{
	if (mlx->camera.ray_dir.x == 0)
	{
		mlx->camera.delta_dist.x = 1;
		mlx->camera.delta_dist.y = 0;
	}
	else
		if (mlx->camera.ray_dir.y)
			mlx->camera.delta_dist.x = abs_d(1 / mlx->camera.ray_dir.x);
	if (mlx->camera.ray_dir.y == 0)
	{
		mlx->camera.delta_dist.x = 0;
		mlx->camera.delta_dist.y = 1;
	}
	else
		if (mlx->camera.ray_dir.x)
			mlx->camera.delta_dist.y = abs_d(1 / mlx->camera.ray_dir.y);
}

void	dist_to_side_x(t_mlx *mlx, int step[2])
{
	double	wall;

	if (mlx->camera.ray_dir.x < 0)
	{
		wall = (mlx->camera.position.x - (double)mlx->camera.map_pos.x);
		mlx->camera.dist_to_side.x = wall * mlx->camera.delta_dist.x;
		step[X] = -1;
	}
	else
	{
		wall = ((double)mlx->camera.map_pos.x + 1 - mlx->camera.position.x);
		mlx->camera.dist_to_side.x = wall * mlx->camera.delta_dist.x;
		step[X] = 1;
	}
}

void	dist_to_side_y(t_mlx *mlx, int step[2])
{
	double	wall;

	if (mlx->camera.ray_dir.y < 0)
	{
		wall = (mlx->camera.position.y - (double)mlx->camera.map_pos.y);
		mlx->camera.dist_to_side.y = wall * mlx->camera.delta_dist.y;
		step[Y] = -1;
	}
	else
	{
		wall = ((double)mlx->camera.map_pos.y + 1 - mlx->camera.position.y);
		mlx->camera.dist_to_side.y = wall * mlx->camera.delta_dist.y;
		step[Y] = 1;
	}
}
