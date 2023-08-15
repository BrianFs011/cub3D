/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:45:53 by briferre          #+#    #+#             */
/*   Updated: 2023/08/15 15:28:03 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	deallocate_memory(t_mlx *mlx)
{
	free(mlx->mlx_ptr);
	free(mlx->map.matrix);
	free(mlx->map.tex_ea);
	free(mlx->map.tex_no);
	free(mlx->map.tex_so);
	free(mlx->map.tex_we);
	ft_lstclear(&mlx->file_loaded, del);
}
