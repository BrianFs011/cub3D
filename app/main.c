/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:14:19 by briferre          #+#    #+#             */
/*   Updated: 2023/09/10 17:49:54 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	render(t_mlx *mlx)
{
	if (mlx->unlook)
	{
		load_background(&mlx->img, mlx->map.color_floor, mlx->map.color_ceil);
		engine(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
		mlx->unlook = 0;
	}
	return (0);
}

void	validate_args(int argc, char **argv)
{
	int	offset;

	if (argc != 2)
		exit_error(ARGUMENT_ERROR, NULL);
	offset = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".cub", argv[1] + offset, 5) != 0)
		exit_error(FILE_TYPE_ERROR, NULL);
}

void	init_variables(t_mlx *mlx)
{
	mlx->unlook = 1;
	mlx->error.type = 0;
	mlx->error.error_message = "Não definido";
	mlx->file_loaded = NULL;
	mlx->texture.path_ea = NULL;
	mlx->texture.path_no = NULL;
	mlx->texture.path_so = NULL;
	mlx->texture.path_we = NULL;
	mlx->map.matrix = NULL;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	validate_args(argc, argv);
	init_variables(&mlx);
	cam_init(&mlx);
	get_map(&mlx, argv);
	set_orientation(&mlx);
	window_init(&mlx);
	image_init(&mlx);
	if (!mlx.error.type)
	{
		mlx_loop_hook(mlx.mlx_ptr, render, &mlx);
		mlx_key_hook(mlx.win_ptr, &handle_key_press, &mlx);
		mlx_hook(mlx.win_ptr, 17, 0, close_program, &mlx);
		mlx_hook(mlx.win_ptr, 2, 1L << 0, NULL, NULL);
		mlx_loop(mlx.mlx_ptr);
	}
	else
		printf("%s\n", mlx.error.error_message);
	close_program(&mlx);
	return (0);
}
