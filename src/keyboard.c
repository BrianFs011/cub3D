/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:20:56 by briferre          #+#    #+#             */
/*   Updated: 2023/07/17 08:29:26 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	handle_key_press(int keycode, t_mlx *mlx)
{
	double	x;
	double	y;

	if (keycode == 'w')
	{
		y = mlx->camera.position.y + 0.2 * cos(degrees_to_radians(mlx->camera.theta));
		if (mlx->map[(int)(mlx->camera.position.x)][(int)(y)] != '1')
			mlx->camera.position.y += 0.1 * cos(degrees_to_radians(mlx->camera.theta));
		x = mlx->camera.position.x + 0.2 * sin(degrees_to_radians(mlx->camera.theta));
		if (mlx->map[(int)(x)][(int)(mlx->camera.position.y)] != '1')
			mlx->camera.position.x += 0.1 * sin(degrees_to_radians(mlx->camera.theta));
	}
	if (keycode == 'a')
		mlx->camera.theta -= 3;
	if (keycode == 's')
	{
		y = mlx->camera.position.y - 0.2 * cos(degrees_to_radians(mlx->camera.theta));
		if (mlx->map[(int)(mlx->camera.position.x)][(int)(mlx->camera.position.y - 0.2)] != '1')
			mlx->camera.position.y -= 0.1 * cos(degrees_to_radians(mlx->camera.theta));
		x = mlx->camera.position.x - 0.2 * sin(degrees_to_radians(mlx->camera.theta));
		if (mlx->map[(int)(mlx->camera.position.x - 0.2)][(int)(mlx->camera.position.y)] != '1')
			mlx->camera.position.x -= 0.1 * sin(degrees_to_radians(mlx->camera.theta));
	}
	if (keycode == 'd')
		mlx->camera.theta += 3;
	if (keycode == 65307)
		close_program(mlx);
	mlx->unlook = 1;
	return (0);
}