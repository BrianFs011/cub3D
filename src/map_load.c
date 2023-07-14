/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 08:27:09 by briferre          #+#    #+#             */
/*   Updated: 2023/07/14 09:39:45 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	map_size(int fd)
{
	int		i;
	char	*string;

	i = 0;
	string = get_next_line(fd);
	while (string)
	{
		free(string);
		string = get_next_line(fd);
		i++;
	}
	lseek(fd, 0, SEEK_SET);
	return (i);
}

void	get_map(t_mlx *mlx, int fd)
{
	int		i;
	char	*string;

	mlx->map_size = map_size(fd);
	mlx->map = malloc(sizeof(char *) * mlx->map_size + sizeof(char *));
	i = mlx->map_size + 1;
	mlx->map[--i] = NULL;
	string = get_next_line(fd);
	while (string)
	{
		mlx->map[--i] = string;
		string = get_next_line(fd);
	}
}

void	map_load(t_mlx *mlx)
{
	int	fd;

	(void)mlx;
	fd = open("maps/map2.cub", O_RDONLY);
	get_map(mlx, fd);
	close(fd);
}

void	clear_memory_map(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < mlx->map_size && mlx->map[i])
		free(mlx->map[i]);
	free(mlx->map);
}
