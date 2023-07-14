/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:20:56 by briferre          #+#    #+#             */
/*   Updated: 2023/07/14 10:19:42 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	handle_key_press(int keycode, t_mlx *mlx)
{
	// double	x;
	// double	y;
	// printf("%d\n", keycode);
	mlx->unlook = 1;
	if (keycode == 'w')
	{
		mlx->camera.position.y -= 0.01;
		// x = ternary_d(cos(degrees_to_radians(mlx->camera.theta)) < 0, -mlx->radius, mlx->radius) + mlx->camera.position.x + 2 * cos(degrees_to_radians(mlx->camera.theta));
		// y = ternary_d(sin(degrees_to_radians(mlx->camera.theta)) < 0, -mlx->radius, mlx->radius) + mlx->camera.position.y;
		// if (mlx->map[(int)(y / 100)][(int)(x / 100)] != '1')
		// {
		// 	mlx->camera.position.x += 2 * cos(degrees_to_radians(mlx->camera.theta));
		// }
		// x = ternary_d(cos(degrees_to_radians(mlx->camera.theta)) < 0, -mlx->radius, mlx->radius) + mlx->camera.position.x;
		// y = ternary_d(sin(degrees_to_radians(mlx->camera.theta)) < 0, -mlx->radius, mlx->radius) + mlx->camera.position.y + 2 * sin(degrees_to_radians(mlx->camera.theta));
		// if (mlx->map[(int)(y / 100)][(int)(x / 100)] != '1')
		// 	mlx->camera.position.y += 2 * sin(degrees_to_radians(mlx->camera.theta));
	}
	if (keycode == 'a')
	{
		mlx->camera.theta += 5.0;
		mlx->camera.position.x -= 0.01;
	}
	if (keycode == 's')
	{
		mlx->camera.position.y += 0.01;
		// x = ternary_d(cos(degrees_to_radians(mlx->camera.theta)) < 0, mlx->radius, -mlx->radius) + mlx->camera.position.x - 2 * cos(degrees_to_radians(mlx->camera.theta));
		// y = ternary_d(sin(degrees_to_radians(mlx->camera.theta)) < 0, mlx->radius, -mlx->radius) + mlx->camera.position.y - 2 * sin(degrees_to_radians(mlx->camera.theta));
		// if (mlx->map[(int)(y / 100)][(int)(x / 100)] != '1')
		// {
		// 	mlx->camera.position.x -= 2 * cos(degrees_to_radians(mlx->camera.theta));
		// 	mlx->camera.position.y -= 2 * sin(degrees_to_radians(mlx->camera.theta));
		// }
	}
	if (keycode == 'd')
	{
		mlx->camera.position.x += 0.01;
		mlx->camera.theta -= 5.0;
	}
	if (keycode == 65307)
		close_program(mlx);
	return (0);
}

	// printf("Position: %.f %.f\n", mlx->camera.x, mlx->camera.y);
	/*
		Matrix [y][x]
			x x x
		y
		y
		y
	*/
