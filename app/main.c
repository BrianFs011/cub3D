/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:14:19 by briferre          #+#    #+#             */
/*   Updated: 2023/07/23 03:59:00 by briferre         ###   ########.fr       */
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

void	set_orientation(t_mlx *mlx)
{
	int		p[2];

	p[X] = mlx->camera.position.x;
	p[Y] = mlx->camera.position.y;
	if (mlx->map[p[X]][p[Y]] == 'N')
		mlx->camera.theta = 270;
	else if (mlx->map[p[X]][p[Y]] == 'W')
		mlx->camera.theta = 180;
	else if (mlx->map[p[X]][p[Y]] == 'S')
		mlx->camera.theta = 90;
	else if (mlx->map[p[X]][p[Y]] == 'E')
		mlx->camera.theta = 0;
}

int	check_personage(t_mlx mlx)
{
	if (mlx.camera.position.x == -1 && mlx.camera.position.y == -1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argc;
	mlx.unlook = 1;
	cam_init(&mlx);
	map_load(&mlx, argv);
	if (check_personage(mlx))
	{
		set_orientation(&mlx);
		window_init(&mlx);
		image_init(&mlx);
		mlx_loop_hook(mlx.mlx_ptr, render, &mlx);
		mlx_key_hook(mlx.win_ptr, &handle_key_press, &mlx);
		mlx_hook(mlx.win_ptr, 17, 0, close_program, &mlx);
		mlx_hook(mlx.win_ptr, 2, 1L << 0, NULL, NULL);
		mlx_loop(mlx.mlx_ptr);
	}
	else
		printf("Erro, personagem não encontrado\n");
	return (0);
}
