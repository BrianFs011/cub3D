/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:53:51 by briferre          #+#    #+#             */
/*   Updated: 2023/09/10 10:41:55 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	find_wall_pos(t_mlx *mlx, int step[2])
{
	int	hit;
	int	p[2];

	hit = 0;
	while (hit == 0)
	{
		if (mlx->camera.dda_line_size.x < mlx->camera.dda_line_size.y)
		{
			mlx->camera.wall_map_pos.x += step[X];
			mlx->camera.dda_line_size.x += mlx->camera.delta_dist.x;
			mlx->camera.hit_side = 0;
			mlx->camera.cardinal = ternary_e(mlx->camera.ray_dir.x > 0, so, no);
		}
		else
		{
			mlx->camera.wall_map_pos.y += step[Y];
			mlx->camera.dda_line_size.y += mlx->camera.delta_dist.y;
			mlx->camera.hit_side = 1;
			mlx->camera.cardinal = ternary_e(mlx->camera.ray_dir.y > 0, we, ea);
		}
		p[0] = mlx->camera.wall_map_pos.x;
		p[1] = mlx->camera.wall_map_pos.y;
		if (mlx->map.matrix[p[0]][p[1]] == '1')
			hit = 1;
	}
}

void	perpendicular_dist(t_mlx *mlx, int step[2])
{
	double	p;
	double	d;

	if (mlx->camera.hit_side == 0)
	{
		p = mlx->camera.wall_map_pos.x - mlx->camera.position.x;
		d = (1 - step[X]) / 2;
		mlx->camera.perpendicular_dist = abs_d((p + d) / mlx->camera.ray_dir.x);
	}
	else
	{
		p = mlx->camera.wall_map_pos.y - mlx->camera.position.y;
		d = (1 - step[Y]) / 2;
		mlx->camera.perpendicular_dist = abs_d((p + d) / mlx->camera.ray_dir.y);
	}
}

void	horizontal_loop(t_mlx *mlx, int i)
{
	double	multiplier;
	int		step[2];

	multiplier = 2 * (double)i / (double)WIDTH - 1;
	mlx->camera.pixel = vector_emultiple(mlx->camera.plane, multiplier);
	mlx->camera.ray_dir = vector_add(mlx->camera.direction,
			mlx->camera.pixel);
	delta_dist(mlx);
	mlx->camera.map_pos.x = (int)mlx->camera.position.x;
	mlx->camera.map_pos.y = (int)mlx->camera.position.y;
	dist_to_side_x(mlx, step);
	dist_to_side_y(mlx, step);
	mlx->camera.dda_line_size.x = mlx->camera.dist_to_side.x;
	mlx->camera.dda_line_size.y = mlx->camera.dist_to_side.y;
	mlx->camera.wall_map_pos.x = mlx->camera.map_pos.x;
	mlx->camera.wall_map_pos.y = mlx->camera.map_pos.y;
	find_wall_pos(mlx, step);
	perpendicular_dist(mlx, step);
	draw(mlx, i);
}

void	engine(t_mlx *mlx)
{
	int		i;

	mlx->camera.direction = vector_init(0, 1, 0, 0);
	mlx->camera.direction = vector_rotate_p(mlx->camera.direction,
			mlx->camera.theta);
	mlx->camera.plane = vector_init(0.66, 0, 0, 0);
	mlx->camera.plane = vector_rotate_p(mlx->camera.plane, mlx->camera.theta);
	i = -1;
	while (++i < WIDTH)
		horizontal_loop(mlx, i);
}
