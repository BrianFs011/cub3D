/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:14:19 by briferre          #+#    #+#             */
/*   Updated: 2023/07/23 02:48:10 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	render(t_mlx *mlx)
{
	if (mlx->unlook)
	{
		load_background(&mlx->img);
		engine(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
		mlx->unlook = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argc;
	mlx.unlook = 1;
	cam_init(&mlx);
	map_load(&mlx, argv);
	window_init(&mlx);
	image_init(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, render, &mlx);
	mlx_key_hook(mlx.win_ptr, &handle_key_press, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, close_program, &mlx);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, NULL, NULL);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
