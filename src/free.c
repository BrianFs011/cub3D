/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:45:53 by briferre          #+#    #+#             */
/*   Updated: 2023/08/14 14:46:12 by briferre         ###   ########.fr       */
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
