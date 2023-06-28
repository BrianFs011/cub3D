/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 21:20:56 by briferre          #+#    #+#             */
/*   Updated: 2023/06/27 21:51:12 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	handle_key_press(int keycode, t_mlx *mlx)
{
	printf("Tecla pressionada: %d\n", keycode);
	if (keycode == 'w')
		mlx->camera.y += 10.0;
	if (keycode == 'a')
		mlx->camera.theta -= 10.0;
	if (keycode == 's')
		mlx->camera.y -= 10.0;
	if (keycode == 'd')
		mlx->camera.theta += 10.0;


	// mlx->camera.modulo_cam = sqrt(
	// 		pow(mlx->camera.x, 2.0) + pow(mlx->camera.y, 2.0));
	// mlx->camera.x = mlx->camera.modulo_cam * cos(
	// 		degrees_to_radians(mlx->camera.theta));
	// mlx->camera.y = mlx->camera.modulo_cam * sin(
	// 		degrees_to_radians(mlx->camera.theta));


	load_background(&mlx->img, create_trgb(0, 0, 0, 0));
	return (0);
}
