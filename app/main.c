/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:14:19 by briferre          #+#    #+#             */
/*   Updated: 2023/08/21 03:12:27 by sde-cama         ###   ########.fr       */
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
	mlx->map.tex_ea = NULL;
	mlx->map.tex_no = NULL;
	mlx->map.tex_so = NULL;
	mlx->map.tex_we = NULL;
	mlx->map.matrix = NULL;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	validate_args(argc, argv);
	init_variables(&mlx);
	cam_init(&mlx);
	get_file(&mlx, argv);
	get_style(&mlx);
	get_map(&mlx);
	if (!mlx.error.type)
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
		printf("%s\n", mlx.error.error_message);
	return (0);
}
