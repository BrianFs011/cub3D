/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:35:14 by briferre          #+#    #+#             */
/*   Updated: 2023/06/22 18:43:36 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cam_init(t_mlx *mlx)
{
	//posição da camera
	mlx->camera.x = 100.0;
	mlx->camera.y = 100.0;
	mlx->camera.z = 0.0;
	//onde a camera aponta
	mlx->camera.looking_x = 300.0;
	mlx->camera.looking_y = 300.0;
	mlx->camera.looking_z = 0.0;
	//angulo da camera
	mlx->camera.phi = 45.0;
	mlx->camera.theta = 0.0;
}
