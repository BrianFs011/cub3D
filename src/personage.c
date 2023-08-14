/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   personage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:25:20 by briferre          #+#    #+#             */
/*   Updated: 2023/08/12 14:34:06 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_orientation(t_mlx *mlx)
{
	int		p[2];

	p[X] = mlx->camera.position.x;
	p[Y] = mlx->camera.position.y;
	if (mlx->map.matrix[p[X]][p[Y]] == 'N')
		mlx->camera.theta = 270;
	else if (mlx->map.matrix[p[X]][p[Y]] == 'W')
		mlx->camera.theta = 180;
	else if (mlx->map.matrix[p[X]][p[Y]] == 'S')
		mlx->camera.theta = 90;
	else if (mlx->map.matrix[p[X]][p[Y]] == 'E')
		mlx->camera.theta = 0;
}

t_points	find_personage(char *string, t_points cp, int i)
{
	t_points	p;
	int			j;

	j = -1;
	p.x = cp.x;
	p.y = cp.y;
	while (string[++j])
	{
		if (string[j] == 'N'
			|| string[j] == 'S'
			|| string[j] == 'E'
			|| string[j] == 'W')
		{
			p.x = (double)i + 0.5;
			p.y = (double)j + 0.5;
			return (p);
		}
	}
	return (p);
}
