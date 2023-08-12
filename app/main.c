/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:14:19 by briferre          #+#    #+#             */
/*   Updated: 2023/08/12 12:46:25 by sde-cama         ###   ########.fr       */
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

void	del(void *d)
{
	char	*string;

	string = d;
	free(string);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (!validate_args(argc, argv))
		return (1);
	mlx.unlook = 1;
	mlx.error.error = 0;
	mlx.error.error_message = "Não definido";
	mlx.file_loaded = NULL;
	cam_init(&mlx);
	get_file(&mlx, argv);
	get_style(&mlx);
	get_map(&mlx);
	if (!mlx.error.error)
	{
		set_orientation(&mlx);
		window_init(&mlx);
		image_init(&mlx);
		mlx_loop_hook(mlx.mlx_ptr, render, &mlx);
		mlx_key_hook(mlx.win_ptr, &handle_key_press, &mlx);
		mlx_hook(mlx.win_ptr, 17, 0, close_program, &mlx);
		mlx_hook(mlx.win_ptr, 2, 1L << 0, NULL, NULL);
		// printf("aqi\n");
		mlx_loop(mlx.mlx_ptr);
	}
	else
		printf("%s\n", mlx.error.error_message);
	ft_lstclear(&mlx.file_loaded, &del);
	return (0);
}
