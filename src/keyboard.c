/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:20:56 by briferre          #+#    #+#             */
/*   Updated: 2023/09/10 10:17:32 by briferre         ###   ########.fr       */
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

void	key_a(t_mlx *mlx)
{
	double	x;
	double	y;
	double	a;

	a = mlx->camera.theta;
	y = mlx->camera.position.y + 0.2 * sin(degrees_to_radians(a));
	if (mlx->map.matrix[(int)(mlx->camera.position.x)][(int)(y)] != '1')
		mlx->camera.position.y += 0.1 * sin(degrees_to_radians(a));
	x = mlx->camera.position.x - 0.2 * cos(degrees_to_radians(a));
	if (mlx->map.matrix[(int)(x)][(int)(mlx->camera.position.y)] != '1')
		mlx->camera.position.x -= 0.1 * cos(degrees_to_radians(a));
}

void	key_d(t_mlx *mlx)
{
	double	x;
	double	y;
	double	a;

	a = mlx->camera.theta;
	y = mlx->camera.position.y - 0.2 * sin(degrees_to_radians(a));
	if (mlx->map.matrix[(int)(mlx->camera.position.x)][(int)(y)] != '1')
		mlx->camera.position.y -= 0.1 * sin(degrees_to_radians(a));
	x = mlx->camera.position.x + 0.2 * cos(degrees_to_radians(a));
	if (mlx->map.matrix[(int)(x)][(int)(mlx->camera.position.y)] != '1')
		mlx->camera.position.x += 0.1 * cos(degrees_to_radians(a));
}

int	handle_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == XK_w)
		key_w(mlx);
	if (keycode == XK_a)
		key_a(mlx);
	if (keycode == XK_s)
		key_s(mlx);
	if (keycode == XK_d)
		key_d(mlx);
	if (keycode == XK_Right)
		mlx->camera.theta += 3.01;
	if (keycode == XK_Left)
		mlx->camera.theta -= 2.99;
	if (keycode == XK_Escape)
		close_program(mlx);
	mlx->unlook = 1;
	return (0);
}
