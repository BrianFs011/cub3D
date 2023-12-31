/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vertical_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 02:53:35 by sde-cama          #+#    #+#             */
/*   Updated: 2023/09/13 00:55:36 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_map_col(t_mlx *mlx, int *inside_map, int i, int j)
{
	if (mlx->map.matrix[i][j] == '1' && *inside_map == FALSE)
		*inside_map = TRUE;
	if (mlx->map.matrix[i][j] == ' ' && *inside_map == TRUE)
		*inside_map = FALSE;
	if (mlx->map.matrix[i][j] == '0' && *inside_map == FALSE)
		return (1);
	if (mlx->map.matrix[i][j] == '0' && *inside_map == TRUE &&
		mlx->map.matrix[i + 1] != NULL && i != 0)
		if (mlx->map.matrix[i + 1][j] == '\0' ||
			mlx->map.matrix[i + 1][j] == ' ' ||
			mlx->map.matrix[i + 1][j] == '\n' ||
			mlx->map.matrix[i - 1][j] == '\0' ||
			mlx->map.matrix[i - 1][j] == ' ' ||
			mlx->map.matrix[i - 1][j] == '\n')
			return (1);
	if (mlx->map.matrix[i][j] == '0' &&
		(mlx->map.matrix[i + 1] == NULL || i == 0))
		return (1);
	return (0);
}

void	find_map_width(t_mlx *mlx)
{
	int	i;

	i = -1;
	mlx->map_width = 0;
	while (mlx->map.matrix[++i] != NULL)
	{
		if (ft_strlen(mlx->map.matrix[i]) > mlx->map_width)
			mlx->map_width = ft_strlen(mlx->map.matrix[i]);
	}
}

int	check_map_vertically(t_mlx *mlx)
{
	int	i;
	int	j;
	int	inside_map;

	inside_map = FALSE;
	find_map_width(mlx);
	j = -1;
	while (++j < mlx->map_width)
	{
		i = -1;
		while (mlx->map.matrix[++i] != NULL)
		{
			if (j <= ft_strlen(mlx->map.matrix[i]))
			{
				if (check_map_col(mlx, &inside_map, i, j) == 1)
					return (set_error_msg(mlx, MAP_CONFIG_ERROR));
			}
		}
		inside_map = FALSE;
	}
	return (0);
}
