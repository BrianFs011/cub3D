/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:14:19 by briferre          #+#    #+#             */
/*   Updated: 2023/07/12 16:06:11 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	map_position(double p)
{
	return (p / 100);
}

int	render(t_mlx *mlx)
{
	double	*ray_direction;
	double	*delta_distance;
	double	*position;
	// double	*distince_side;

	if (mlx->unlook)
	{
		load_background(&mlx->img);
		ray_direction  = vector_points_d(0, 0, 0, 0);
		delta_distance = vector_points_d(0, 0, 0, 0);
		position       = vector_points_d(100, 100, 0, 0);
		// distince_side  = vector_points_d(0, 0, 0, 0);

		ray_direction[X] = ray_to_plane(100, 200, ray_multiple(0));
		ray_direction[Y] = ray_to_plane(100, 200, ray_multiple(0));

		delta_distance[X] = magnitude(delta_distance[X], delta_distance[Y]) / delta_distance[X];
		delta_distance[Y] = magnitude(delta_distance[X], delta_distance[Y]) / delta_distance[Y];
		delta_distance[X] = ternary_d(delta_distance[X] < 0, -delta_distance[X], delta_distance[X]);
		delta_distance[Y] = ternary_d(delta_distance[Y] < 0, -delta_distance[Y], delta_distance[Y]);

		// double stepX = 0;
		// double stepY = 0;

		// if (ray_direction[X] < 0)
		// {
		// 	stepX -= 1;
		// 	distince_side[X] = (position[X] - map_position(position[X])) * delta_distance[X];
		// }
		// else
		// {
		// 	distince_side[X] = (map_position(position[X]) + 1 - position[X]) * delta_distance[X];
		// 	stepX += 1;
		// }
		// if (ray_direction[Y] < 0)
		// {
		// 	stepX -= 1;
		// 	distince_side[Y] = (position[Y] - map_position(position[Y])) * delta_distance[Y];
		// }
		// else
		// {
		// 	stepX += 1;
		// 	distince_side[Y] = (map_position(position[Y]) + 1 - position[Y]) * delta_distance[Y];
		// }
		// int hit_side;
		// int hit = 0;
		// double ddaLineSizeX = distince_side[X];
		// double ddaLineSizeY = distince_side[Y];
		// int *wallMapPos = vector_points_i(map_position(position[X]), map_position(position[Y]), 0, 0);

		// while (hit == 0)
		// {
		// 	if (ddaLineSizeX < ddaLineSizeY)
		// 	{
		// 		wallMapPos[X] += stepX;
		// 		ddaLineSizeX += delta_distance[X];
		// 		// hit_side = 0;
		// 	}
		// 	else
		// 	{
		// 		wallMapPos[Y] += stepY;
		// 		ddaLineSizeY += delta_distance[Y];
		// 		// hit_side = 1;
		// 	}
		// 	if (mlx->map[wallMapPos[X]][wallMapPos[Y]] == '1')
		// 		hit = 1;
		// }

		// ---
		// draw_line(&mlx->img, vector_points_i(100, 200, 100, 100), create_trgb(0, 255, 0, 0));
		// draw_line(&mlx->img, vector_points_i(200, 200, 100, 200), create_trgb(0, 255, 0, 0));
		// draw_line(&mlx->img, vector_points_i(100, 200, 200, 200), create_trgb(0, 255, 0, 0));
		// draw_line(&mlx->img, vector_points_i(100, 100, 200, 100), create_trgb(0, 255, 0, 0));
		// ---

		double wall_size = HEIGHT / mlx->camera.position.y * 100;
		for (int i = 0; i < 600; i++)
		{
			draw_line(&mlx->img,
				vector_points_i(i,
												i,
												(HEIGHT / 2) - (wall_size / 2),
												(HEIGHT / 2) + (wall_size / 2)),
				create_trgb(0, 255, 0, 0));
		}

		printf("%lf\n", HEIGHT / mlx->camera.position.y * 100);


		// double deltaY = 100 * (sin(degrees_to_radians(mlx->camera.theta)) * 100) / (cos(degrees_to_radians(mlx->camera.theta)) * 100);

		// draw_line(&mlx->img,
		// 	vector_points_i(position[X],
		// 									position[X] + cos(degrees_to_radians(mlx->camera.theta)) * 100,
		// 									position[Y],
		// 									position[Y] + sin(degrees_to_radians(mlx->camera.theta)) * 100),
		// 	create_trgb(0, 255, 0, 0));

		// double tang = (100 * sin(degrees_to_radians(mlx->camera.theta)) * 100) / (cos(degrees_to_radians(mlx->camera.theta)) * 100);

		// delta_distance[X] = magnitude(cos(degrees_to_radians(mlx->camera.theta)) * 100, sin(degrees_to_radians(mlx->camera.theta)) * 100);

		// draw_line(&mlx->img,
		// 	vector_points_i(position[X],
		// 									position[X] + cos(degrees_to_radians(mlx->camera.theta)) * 100,
		// 									position[Y],
		// 									position[Y] + deltaY),
		// 	create_trgb(0, 0, 255, 0));


		// (map_position(position[Y]) + 1) * 100 - position[Y]

		// printf("%lf %lf\n", ray_to_plane(ray, ray_multiple(0)), ray[1]);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
		mlx->unlook = 0;
		free(position);
		free(ray_direction);
		free(delta_distance);
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
	// for(int x = 0; x < WIDTH; x++)
	// {
	// 	//calculate ray position and direction
	// 	double cameraX = 2 * x / WIDTH - 1; //x-coordinate in camera space
	// 	double rayDirX = mlx.camera.looking.x + mlx.camera.plane.x * mlx.camera.position.x;
	// 	double rayDirY = mlx.camera.looking.y + mlx.camera.plane.y * mlx.camera.position.y;
	// }



		// draw_line(&mlx->img, vector_points(300, 600, 300, 300), create_trgb(0, 0, 255, 0));
		// draw_line(&mlx->img, vector_points(300, 300, 300, 600), create_trgb(0, 255, 0, 0));
		// draw_line(&mlx->img, vector_points(0, 300, 0, 300), create_trgb(0, 0, 0, 255));
		// draw_line(&mlx->img, vector_points(300 + 20, 300 + 20, 300, 400 - mlx->camera.position.x * tan(degrees_to_radians(45))), create_trgb(0, 255, 255, 0));