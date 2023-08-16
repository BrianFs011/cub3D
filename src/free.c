/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:45:53 by briferre          #+#    #+#             */
/*   Updated: 2023/08/16 13:55:06 by briferre         ###   ########.fr       */
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
