/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:20:56 by briferre          #+#    #+#             */
/*   Updated: 2023/06/29 19:06:55 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	posi_to_index(int position)
{
	int	index;

	index = position / 100;
	if (index < 0)
		index = 0;
	if (index > WIDTH / 100)
		index = WIDTH / 100 - 1;
	printf("%d\n", index);
	return (index);
}

int	handle_key_press(int keycode, t_mlx *mlx)
{
	mlx->unlook = 1;
	if (keycode == 'w')
	{
		// if (mlx->map[(int)((mlx->camera.y + 25.0) / 100)][(int)((mlx->camera.x) / 100)] != '1')
			mlx->camera.x += 2 * cos(degrees_to_radians(mlx->camera.theta));
			mlx->camera.y += 2 * sin(degrees_to_radians(mlx->camera.theta));
	}
	if (keycode == 'a')
	{
		mlx->camera.theta += 5.0;
		// if (mlx->map[(int)(mlx->camera.y / 100)][(int)((mlx->camera.x - 30.0) / 100)] != '1')
		// 	mlx->camera.x -= 5.0;
	}
	if (keycode == 's')
	{
			mlx->camera.x -= 2 * cos(degrees_to_radians(mlx->camera.theta));
			mlx->camera.y -= 2 * sin(degrees_to_radians(mlx->camera.theta));
		// if (mlx->map[(int)((mlx->camera.y - 30.0) / 100)][(int)((mlx->camera.x) / 100)] != '1')
		// 	mlx->camera.y -= 5.0;
	}
	if (keycode == 'd')
	{
		mlx->camera.theta -= 5.0;
		// if (mlx->map[(int)(mlx->camera.y / 100)][(int)((mlx->camera.x + 25.0) / 100)] != '1')
		// 	mlx->camera.x += 5.0;
	}
	printf("Position: %.f %.f\n", mlx->camera.x, mlx->camera.y);
	/*
		Matrix [y][x]
			x x x
		y
		y
		y
	*/
	printf("Limite: (%d, %d) %c\n",
		(int)((mlx->camera.x + 10.0) / 100.0), // x
		(int)(mlx->camera.y / 100.0),          // y
		mlx->map[(int)(mlx->camera.y / 100)][(int)((mlx->camera.x + 10.0) / 100)]);
	load_background(&mlx->img, create_trgb(0, 0, 0, 0));
	return (0);
}
