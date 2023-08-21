/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:45:53 by briferre          #+#    #+#             */
/*   Updated: 2023/08/21 02:50:09 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clear_tex_name(t_mlx *mlx)
{
	free(mlx->map.tex_ea);
	free(mlx->map.tex_no);
	free(mlx->map.tex_so);
	free(mlx->map.tex_we);
}

void	exit_error(char *error, t_mlx *mlx)
{
	if (mlx)
	{
		ft_lstclear(&mlx->file_loaded, del);
		free(mlx->map.tex_ea);
		free(mlx->map.tex_no);
		free(mlx->map.tex_so);
		free(mlx->map.tex_we);
		if (mlx->map.matrix != NULL)
			free(mlx->map.matrix);
	}
	ft_putendl_fd(error, 2);
	exit(0);
}
