#include "header.h"

void	save_texture_pixels(t_mlx *mlx);
int		img_pix_get(t_data *img, int x, int y);
void	init_textures(t_mlx *mlx, t_data *img, char *path);

void	initialize_textures(t_mlx *mlx)
{
	init_textures(mlx, &mlx->txt_img_NO, "/home/sathya/backup/42/cub3d/cub3D/textures/texture1.xpm");
	init_textures(mlx, &mlx->txt_img_SO, "/home/sathya/backup/42/cub3d/cub3D/textures/texture2.xpm");
	init_textures(mlx, &mlx->txt_img_WE, "/home/sathya/backup/42/cub3d/cub3D/textures/texture3.xpm");
	init_textures(mlx, &mlx->txt_img_EA, "/home/sathya/backup/42/cub3d/cub3D/textures/texture4.xpm");
	save_texture_pixels(mlx);
}

void	init_textures(t_mlx *mlx, t_data *img, char *path)
{
	int	height;
	int	width;

	img->img = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &width, &height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	save_texture_pixels(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < texWidth)
	{
		j = 0;
		while (j < texHeight)
		{
			mlx->textureNO[i][j] = img_pix_get(&mlx->txt_img_NO, j, i);
			mlx->textureSO[i][j] = img_pix_get(&mlx->txt_img_SO, j, i);
			mlx->textureWE[i][j] = img_pix_get(&mlx->txt_img_WE, j, i);
			mlx->textureEA[i][j] = img_pix_get(&mlx->txt_img_EA, j, i);
			j++;
		}
		i++;
	}
}

int	img_pix_get(t_data *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(int *)pixel);
}
