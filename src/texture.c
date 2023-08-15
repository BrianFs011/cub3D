/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:58:12 by briferre          #+#    #+#             */
/*   Updated: 2023/08/15 15:10:21 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_textures(t_mlx *mlx, t_data *img, char *path)
{
	int	height;
	int	width;

	img->img = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &width, &height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

int	img_pix_get(t_data *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(int *)pixel);
}

void	save_texture_pixels(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < TEXWIDTH)
	{
		j = 0;
		while (j < TEXHEIGHT)
		{
			mlx->texture.no[i][j] = img_pix_get(&mlx->texture.img_no, j, i);
			mlx->texture.so[i][j] = img_pix_get(&mlx->texture.img_so, j, i);
			mlx->texture.we[i][j] = img_pix_get(&mlx->texture.img_we, j, i);
			mlx->texture.ea[i][j] = img_pix_get(&mlx->texture.img_ea, j, i);
			j++;
		}
		i++;
	}
}

void	initialize_textures(t_mlx *mlx)
{
	init_textures(mlx, &mlx->texture.img_no, "./textures/texture1.xpm");
	init_textures(mlx, &mlx->texture.img_so, "./textures/texture2.xpm");
	init_textures(mlx, &mlx->texture.img_we, "./textures/texture3.xpm");
	init_textures(mlx, &mlx->texture.img_ea, "./textures/texture4.xpm");
	save_texture_pixels(mlx);
}
