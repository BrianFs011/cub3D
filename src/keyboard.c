/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:20:56 by briferre          #+#    #+#             */
/*   Updated: 2023/06/28 19:30:05 by briferre         ###   ########.fr       */
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
		if (mlx->map[(int)((mlx->camera.y + 10.0) / 100)][(int)((mlx->camera.x) / 100)] != '1')
			mlx->camera.y += 10.0;
	}
	if (keycode == 'a')
	{
		if (mlx->map[(int)(mlx->camera.y / 100)][(int)((mlx->camera.x - 10.0) / 100)] != '1')
			mlx->camera.x -= 10.0;
	}
	if (keycode == 's')
	{
		if (mlx->map[(int)((mlx->camera.y - 10.0) / 100)][(int)((mlx->camera.x) / 100)] != '1')
			mlx->camera.y -= 10.0;
	}
	if (keycode == 'd')
	{
		if (mlx->map[(int)(mlx->camera.y / 100)][(int)((mlx->camera.x + 10.0) / 100)] != '1')
			mlx->camera.x += 10.0;
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
