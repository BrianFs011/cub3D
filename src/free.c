/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:45:53 by briferre          #+#    #+#             */
/*   Updated: 2023/08/25 02:50:18 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	deallocate_memory(t_mlx *mlx)
{
	free(mlx->mlx_ptr);
	free(mlx->map.matrix);
	free(mlx->texture.path_ea);
	free(mlx->texture.path_no);
	free(mlx->texture.path_we);
	free(mlx->texture.path_so);
	ft_lstclear(&mlx->file_loaded, del);
}

void	exit_error(char *error, t_mlx *mlx)
{
	if (mlx)
	{
		ft_lstclear(&mlx->file_loaded, del);
		free(mlx->texture.path_ea);
		free(mlx->texture.path_no);
		free(mlx->texture.path_we);
		free(mlx->texture.path_so);
		if (mlx->map.matrix != NULL)
			free(mlx->map.matrix);
	}
	ft_putendl_fd(error, 2);
	exit(0);
}

void	del(void *d)
{
	char	*string;

	(void)d;
	string = d;
	free(string);
}
