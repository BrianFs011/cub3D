/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:49:04 by briferre          #+#    #+#             */
/*   Updated: 2023/08/19 03:39:07 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	window_init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		printf("Erro\n");
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!mlx->win_ptr)
		printf("Erro\n");
}

int	close_program(t_mlx *mlx)
{
	(void)mlx;
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	clear_tex_name(mlx);
	ft_lstclear(&mlx->file_loaded, del);
	free(mlx->map.matrix);
	exit(EXIT_SUCCESS);
	return (0);
}
