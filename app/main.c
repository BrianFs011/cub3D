/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:14:19 by briferre          #+#    #+#             */
/*   Updated: 2023/06/29 19:22:00 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	object_init(t_mlx *mlx)
{
	mlx->radius = 25.0;
}

int	*vector_points(int p0, int p1, int p2, int p3)
{
	int	*p;

	p = malloc(sizeof(int) * 4);
	p[0] = p0;
	p[1] = p1;
	p[2] = p2;
	p[3] = p3;
	return (p);
}

void	draw_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	// while (mlx->map[++i] && i < 5)
	while (mlx->map[++i])
	{
		j = -1;
		// while (mlx->map[++j] && j < 1)
		while (mlx->map[++j])
			if (mlx->map[j][i] == '1')
				draw_rect(&mlx->img, vector_points(i * 100,
						j * 100, 0, 0),
					create_trgb(0, 255, 0, 0));
	}
}

void	draw_direction(t_mlx *mlx, int *p, int r, int color)
{
	printf("r(%f) %fi %fj\n", mlx->camera.theta, r * cos(degrees_to_radians(mlx->camera.theta)), r * sin(degrees_to_radians(mlx->camera.theta)));
	draw_line(&mlx->img, vector_points(
			p[X],
			p[X] + r * cos(degrees_to_radians(mlx->camera.theta)),
			p[Y],
			p[Y] + r * sin(degrees_to_radians(mlx->camera.theta))),
		color);
	free(p);
}

void	draw_objects(t_mlx *mlx)
{
	draw_map(mlx);
	draw_circle(&mlx->img,
		vector_points(mlx->camera.x, mlx->camera.y, 0, 0), mlx->radius,
		create_trgb(0, 0, 255, 0));
	draw_direction(mlx,
		vector_points(mlx->camera.x, mlx->camera.y, 0, 0), mlx->radius,
		create_trgb(0, 0, 0, 255));
}


int	render(t_mlx *mlx)
{
	if (mlx->unlook)
	{
		draw_objects(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
		mlx->unlook = 0;
	}
	return (0);
}

void	clear_memory_map(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < mlx->map_size && mlx->map[i])
		free(mlx->map[i]);
	free(mlx->map);
}

int	close_program(t_mlx *mlx)
{
	(void)mlx;
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	clear_memory_map(mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argc;
	(void)argv;
	mlx.unlook = 1;
	map_load(&mlx);
	window_init(&mlx);
	image_init(&mlx);
	cam_init(&mlx);
	object_init(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, render, &mlx);
	mlx_key_hook(mlx.win_ptr, &handle_key_press, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, close_program, &mlx);
	mlx_hook(mlx.win_ptr, 2, 1L<<0, NULL, NULL);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
