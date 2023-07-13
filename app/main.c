/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:14:19 by briferre          #+#    #+#             */
/*   Updated: 2023/07/13 19:20:41 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	render(t_mlx *mlx)
{
	if (mlx->unlook)
	{
		load_background(&mlx->img);
		double	*position = vector_points_d(mlx->camera.position.x, mlx->camera.position.y, 0, 0);
		double	*direction = vector_points_d(0, 1, 0, 0);
		double	*camera_plane = vector_points_d(0.66, 0, 0, 0);

		for (int i = 0; i < WIDTH; i++)
		{
			double multiple = 2 * (double)i / (double)WIDTH - 1;
			double *camera_pixel = vector_points_d(camera_plane[X] * multiple, camera_plane[Y] * multiple, 0, 0);

			double *ray_dir = vector_points_d(direction[X] + camera_pixel[X], direction[Y] + camera_pixel[Y], 0, 0);

			double delta_dist_x = magnitude(1, ray_dir[Y] / ray_dir[X]);
			double delta_dist_y = magnitude(1, ray_dir[X] / ray_dir[Y]);

			if (ray_dir[X] == 0)
			{
				delta_dist_x = 1;
				delta_dist_y = 0;
			}
			else
			{
				if (ray_dir[Y])
					delta_dist_x = ternary_d(delta_dist_x < 0, -delta_dist_x, delta_dist_x);
			}
			if (ray_dir[Y] == 0)
			{
				delta_dist_x = 0;
				delta_dist_y = 1;
			}
			else
			{
				if (ray_dir[X])
					delta_dist_y = ternary_d(delta_dist_y < 0, -delta_dist_y, delta_dist_y);
			}

			int	*map_pos = vector_points_i(position[X], position[Y], 0, 0);

			double dist_to_side_x;
			double dist_to_side_y;

			int	step_x = 0;
			int	step_y = 0;

			if (ray_dir[X] < 0)
			{
				dist_to_side_x = ((position[X]) - (map_pos[X] * 1)) * delta_dist_x;
				step_x = -1;
			}
			else
			{
				dist_to_side_x = (((map_pos[X] + 1) * 1) - position[X]) * delta_dist_x;
				step_x = 1;

			}
			if (ray_dir[Y] < 0)
			{
				dist_to_side_y = (position[Y] - (map_pos[Y] * 1)) * delta_dist_y;
				step_y = -1;

			}
			else
			{
				dist_to_side_y = (((map_pos[Y] + 1) * 1) - position[Y]) * delta_dist_y;
				step_y = 1;

			}

			int hit = 0;

			int	hit_side;

			int	dda_line_size_x = dist_to_side_x;
			int	dda_line_size_y = dist_to_side_y;

			int	*wall_map_pos = vector_points_i(map_pos[X], map_pos[Y], 0, 0);

			while (hit == 0)
			{
				if (dda_line_size_x < dda_line_size_y)
				{
					wall_map_pos[X] += step_x;
					dda_line_size_x += delta_dist_x;
					hit_side = 0;
				}
				else
				{
					wall_map_pos[Y] += step_y;
					dda_line_size_y += delta_dist_y;
					hit_side = 1;
				}

				if (mlx->map[wall_map_pos[X]][wall_map_pos[Y]] == '1')
					hit = 1;
			}
			double perpendicular_dist;

			if (hit_side == 0)
				perpendicular_dist = ternary_d((wall_map_pos[X] - position[X] + ((1 - step_x) / 2)) / ray_dir[X] < 0, -((wall_map_pos[X] - position[X] + ((1 - step_x) / 2)) / ray_dir[X]), (wall_map_pos[X] - position[X] + ((1 - step_x) / 2)) / ray_dir[X] ) ;
			else
				perpendicular_dist = ternary_d((wall_map_pos[Y] - position[Y] + ((1 - step_y) / 2)) / ray_dir[Y] < 0, -((wall_map_pos[Y] - position[Y] + ((1 - step_y) / 2)) / ray_dir[Y]), (wall_map_pos[Y] - position[Y] + ((1 - step_y) / 2)) / ray_dir[Y] ) ;

			double wall_line_height = HEIGHT / perpendicular_dist;
			draw_line(&mlx->img,
				vector_points_i(i,
												i,
												(HEIGHT / 2) - (wall_line_height / 2),
												(HEIGHT / 2) + (wall_line_height / 2)),
				create_trgb(0, hit_side ? 255 : 128, 0, 0));

			free(map_pos);
			free(wall_map_pos);
			free(camera_pixel);
			free(ray_dir);
		}

		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
		mlx->unlook = 0;
		free(position);
		free(direction);
		free(camera_plane);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argc;
	(void)argv;
	mlx.unlook = 1;
	// ---- Init ----
	map_load(&mlx);
	window_init(&mlx);
	image_init(&mlx);
	cam_init(&mlx);

	// ---- Render ----
	mlx_loop_hook(mlx.mlx_ptr, render, &mlx);

	mlx_key_hook(mlx.win_ptr, &handle_key_press, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, close_program, &mlx);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, NULL, NULL);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
