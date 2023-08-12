/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:23:38 by sde-cama          #+#    #+#             */
/*   Updated: 2023/08/12 19:22:38 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	validate_args(int argc, char **argv)
{
	int	offset;

	if (argc != 2)
		exit_error("Invalid number of arguments. Correct usage: ./cub3D <map_address>");
	offset = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".cub", argv[1] + offset, 5) != 0)
		exit_error("Invalid type of map file. Map file must be .cub");
}

static int	check_char(char c)
{
	if (c != '1' && c != '0' && \
		c != ' ' && c != '\n' && \
		c != 'N' && c != 'S' && \
		c != 'E' && c != 'W')
		return (1);//estora erro se caracter diferente do aceito
	return (0);
}

static int	check_player(t_mlx *mlx, int *player, int i, int j)
{
	if ((mlx->map[i][j]== 'N' || mlx->map[i][j]== 'S' || mlx->map[i][j] == 'E' || mlx->map[i][j] == 'W'))
	{
		*player += 1;
		if (*player > 1)
			return (1);//estora erro se mais de um player
		if (mlx->map[i][j + 1] != '0' && mlx->map[i][j + 1] != '1')
			return (1);
		if (mlx->map[i][j - 1] != '0' && mlx->map[i][j - 1] != '1')
			return (1);
	}
	return (0);
}

static int	check_line(t_mlx *mlx, int *inside_map, int i, int j)
{
	// if (i == mlx->map_height - 1)
	// 	return (0);
	if (mlx->map[i][j] == ' ' && *inside_map == 1)
		if (mlx->map[i][j - 1] != '1')
			return (1);//se colocou espaço vazio no meio do mapa, checa se o anterior era parede
	if (mlx->map[i][j] == ' ' && *inside_map == 0)
		if (mlx->map[i][j + 1] != '1' && \
			mlx->map[i][j + 1] != ' ' && \
			mlx->map[i][j + 1] != '\n')
			return (1);//estora erro se tava fora do mapa, vai botar espaço e prox não é parede ou vazio ou fim da linha
	if (mlx->map[i][j] == '1' && *inside_map == 0)
		*inside_map = 1;//se era epaço vazio e achou parede marca que ta dentro do mapa
	if (mlx->map[i][j] == ' ')
		*inside_map = 0;//se é epaço vazio marca que ta fora do mapa
	if (mlx->map[i][j] == '0' && *inside_map == 0)
		return (1);//estora erro se tava fora do mapa e não é parede
	if (mlx->map[i][j] == '0' && *inside_map == 1 && \
		j == mlx->line_width - 2)
		return (1);//checa se o ultimo caracter da linha é parede
	return (0);
}

int	ft_map_validation(t_mlx *mlx)
{
	int	i;
	int	j;
	int	inside_map;
	int	player;

	i = -1;
	inside_map = 0;
	player = 0;
	while (mlx->map[++i] != NULL)
	{
		j = -1;
		mlx->line_width = ft_strlen(mlx->map[i]);
		while (mlx->map[i][++j] != '\0')
		{
			printf("%c", mlx->map[i][j]);
			if (check_char(mlx->map[i][j]))
				return (1);
			if (check_player(mlx, &player, i, j))
				return (1);
			if (check_line(mlx, &inside_map, i, j))
				return (1);
		}
		inside_map = 0;
	}
	printf("\n");
	if (player != 1)
	{
		// mlx->error.error_message = "Error\nInvalid quantity of Players. Should have only one player";
		return (1);
	}
	// if (check_map_vertically(mlx) == 1)
	// 	return (1);
	return (0);
}
