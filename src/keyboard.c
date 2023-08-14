/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:20:56 by briferre          #+#    #+#             */
/*   Updated: 2023/08/12 14:30:12 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	key_w(t_mlx *mlx)
{
	double	x;
	double	y;
	double	a;

	a = mlx->camera.theta;
	y = mlx->camera.position.y + 0.2 * cos(degrees_to_radians(a));
	if (mlx->map.matrix[(int)(mlx->camera.position.x)][(int)(y)] != '1')
		mlx->camera.position.y += 0.1 * cos(degrees_to_radians(a));
	x = mlx->camera.position.x + 0.2 * sin(degrees_to_radians(a));
	if (mlx->map.matrix[(int)(x)][(int)(mlx->camera.position.y)] != '1')
		mlx->camera.position.x += 0.1 * sin(degrees_to_radians(a));
}

void	key_s(t_mlx *mlx)
{
	double	x;
	double	y;
	double	a;

	a = mlx->camera.theta;
	y = mlx->camera.position.y - 0.2 * cos(degrees_to_radians(a));
	if (mlx->map.matrix[(int)(mlx->camera.position.x)][(int)(y)] != '1')
		mlx->camera.position.y -= 0.1 * cos(degrees_to_radians(a));
	x = mlx->camera.position.x - 0.2 * sin(degrees_to_radians(a));
	if (mlx->map.matrix[(int)(x)][(int)(mlx->camera.position.y)] != '1')
		mlx->camera.position.x -= 0.1 * sin(degrees_to_radians(a));
}

int	handle_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 'w')
		key_w(mlx);
	if (keycode == 'a')
		mlx->camera.theta -= 3;
	if (keycode == 's')
		key_s(mlx);
	if (keycode == 'd')
		mlx->camera.theta += 3;
	if (keycode == 65307)
		close_program(mlx);
	mlx->unlook = 1;
	return (0);
}
