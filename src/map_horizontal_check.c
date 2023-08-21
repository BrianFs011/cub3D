/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_horizontal_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 02:52:35 by sde-cama          #+#    #+#             */
/*   Updated: 2023/08/21 03:03:01 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_char(char c)
{
	if (c != '1' && c != '0' && \
		c != ' ' && c != '\n' && \
		c != 'N' && c != 'S' && \
		c != 'E' && c != 'W')
		return (1);
	return (0);
}

static int	check_player(t_mlx *mlx, int *player, int i, int j)
{
	if ((mlx->map.matrix[i][j] == 'N' || mlx->map.matrix[i][j] == 'S' ||
		mlx->map.matrix[i][j] == 'E' || mlx->map.matrix[i][j] == 'W'))
	{
		*player += 1;
		if (*player > 1)
			return (1);
		if (mlx->map.matrix[i][j + 1] != '0' &&
			mlx->map.matrix[i][j + 1] != '1')
			return (1);
		if (mlx->map.matrix[i][j - 1] != '0' &&
			mlx->map.matrix[i][j - 1] != '1')
			return (1);
	}
	return (0);
}

static int	check_line(t_mlx *mlx, int *inside_map, int i, int j)
{
	if (mlx->map.matrix[i][j] == ' ' && *inside_map == TRUE)
		if (mlx->map.matrix[i][j - 1] != '1')
			return (1);
	if (mlx->map.matrix[i][j] == ' ' && *inside_map == FALSE)
		if (mlx->map.matrix[i][j + 1] != '1' &&
			mlx->map.matrix[i][j + 1] != ' ' &&
			mlx->map.matrix[i][j + 1] != '\n')
			return (1);
	if (mlx->map.matrix[i][j] == '1' && *inside_map == FALSE)
		*inside_map = 1;
	if (mlx->map.matrix[i][j] == ' ')
		*inside_map = 0;
	if (mlx->map.matrix[i][j] == '0' && *inside_map == FALSE)
		return (1);
	if (mlx->map.matrix[i][j] == '0' && *inside_map == TRUE &&
		j == mlx->line_width - 2)
		return (1);
	return (0);
}

int	check_map(t_mlx *mlx)
{
	int	i;
	int	j;
	int	inside_map;
	int	player;

	i = -1;
	player = 0;
	while (mlx->map.matrix[++i] != NULL)
	{
		j = -1;
		inside_map = FALSE;
		mlx->line_width = ft_strlen(mlx->map.matrix[i]);
		while (mlx->map.matrix[i][++j] != '\0')
		{
			if (check_char(mlx->map.matrix[i][j]))
				return (set_error_msg(mlx, CHAR_ERROR));
			if (check_player(mlx, &player, i, j))
				return (set_error_msg(mlx, PLAYER_ERROR));
			if (check_line(mlx, &inside_map, i, j))
				return (set_error_msg(mlx, MAP_CONFIG_ERROR));
		}
	}
	if (player != 1)
		return (set_error_msg(mlx, PLAYER_ERROR));
	return (0);
}
