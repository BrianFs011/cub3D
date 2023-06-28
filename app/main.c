/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:14:19 by briferre          #+#    #+#             */
/*   Updated: 2023/06/28 14:55:44 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*line_points(int x0, int x1, int y0, int y1)
{
	int	*p;

	p = malloc(sizeof(int) * 4);
	p[0] = x0;
	p[1] = x1;
	p[2] = y0;
	p[3] = y1;
	return (p);
}

void	draw_objects(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[++j])
			if (mlx->map[j][i] == '1')
				draw_rect(&mlx->img, line_points(i * 100,
						HEIGHT - j * 100 - 100, 0, 0),
					create_trgb(0, 255, 0, 0));
	}
	// draw_rect(&mlx->img, line_points(100, 0, 0, 0), create_trgb(0, 255, 0, 0));
}

int	render(t_mlx *mlx)
{
	draw_objects(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argc;
	(void)argv;
	map_load(&mlx);
	window_init(&mlx);
	image_init(&mlx);
	cam_init(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, render, &mlx);
	mlx_key_hook(mlx.win_ptr, &handle_key_press, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
