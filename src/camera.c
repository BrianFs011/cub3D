/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:35:14 by briferre          #+#    #+#             */
/*   Updated: 2023/07/28 20:53:33 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cam_init(t_mlx *mlx)
{
	mlx->camera.position.x = 1.5;
	mlx->camera.position.y = 1.5;
	mlx->camera.direction.x = 0.0;
	mlx->camera.direction.y = 1.0;
	mlx->camera.plane.x = 0.66;
	mlx->camera.plane.y = 0;
	mlx->camera.phi = 45.0;
	mlx->camera.theta = 0.0;
	mlx->camera.orientation = 0;
}
