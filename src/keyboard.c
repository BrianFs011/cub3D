/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:20:56 by briferre          #+#    #+#             */
/*   Updated: 2023/07/14 15:14:30 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	handle_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 'w')
	{
		printf("1 - %d %d %c\n", (int)mlx->camera.position.x, (int)(mlx->camera.position.y + 0.2), mlx->map[(int)(mlx->camera.position.x)][(int)(mlx->camera.position.y + 0.10)]);
		if (mlx->map[(int)(mlx->camera.position.x)][(int)(mlx->camera.position.y + 0.1)] != '1'
			&& mlx->map[(int)(mlx->camera.position.x)][(int)(mlx->camera.position.y - 0.1)] != '1')
		{
			mlx->camera.position.y += 0.1 * cos(degrees_to_radians(mlx->camera.theta));
		}
		printf("2 - %lf %lf %c\n", (mlx->camera.position.x + 0.2), mlx->camera.position.y, mlx->map[(int)(mlx->camera.position.x)][(int)(mlx->camera.position.y + 0.10)]);
		if (mlx->map[(int)(mlx->camera.position.x + 0.1)][(int)(mlx->camera.position.y)] != '1'
			&& mlx->map[(int)(mlx->camera.position.x - 0.1)][(int)(mlx->camera.position.y)] != '1')
		{
			mlx->camera.position.x += 0.1 * sin(degrees_to_radians(mlx->camera.theta));
		}
	}
	if (keycode == 'a')
	{
		mlx->camera.theta -= 3;
		// mlx->camera.position.x -= 0.01;
	}
	if (keycode == 's')
	{
		// mlx->camera.position.y -= 0.01;
		if (mlx->map[(int)(mlx->camera.position.x)][(int)(mlx->camera.position.y + 0.1)] != '1'
			&& mlx->map[(int)(mlx->camera.position.x)][(int)(mlx->camera.position.y - 0.1)] != '1')
			mlx->camera.position.y -= 0.1 * cos(degrees_to_radians(mlx->camera.theta));
		if (mlx->map[(int)(mlx->camera.position.x + 0.1)][(int)(mlx->camera.position.y)] != '1'
			&& mlx->map[(int)(mlx->camera.position.x - 0.1)][(int)(mlx->camera.position.y)] != '1')
			mlx->camera.position.x -= 0.1 * sin(degrees_to_radians(mlx->camera.theta));
	}
	if (keycode == 'd')
	{
		mlx->camera.theta += 3;
		// mlx->camera.position.x += 0.01;
	}
	if (keycode == 65307)
		close_program(mlx);
	mlx->unlook = 1;
	return (0);
}