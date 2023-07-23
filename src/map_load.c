/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 08:27:09 by briferre          #+#    #+#             */
/*   Updated: 2023/07/23 03:26:50 by briferre         ###   ########.fr       */
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
			printf("%lf %lf %d %d\n", p.x, p.y, i, j);
			return (p);
		}
	}
	return (p);
}

void	get_map(t_mlx *mlx, int fd)
{
	int		i;
	char	*string;

	mlx->map_size = map_size(fd);
	mlx->map = malloc(sizeof(char *) * mlx->map_size + sizeof(char *));
	i = -1;
	string = get_next_line(fd);
	mlx->camera.position = find_personage(string, mlx->camera.position, i);
	while (string)
	{
		mlx->map[++i] = string;
		mlx->camera.position = find_personage(string, mlx->camera.position, i);
		string = get_next_line(fd);
	}
	mlx->map[++i] = NULL;
}

void	map_load(t_mlx *mlx, char **argv)
{
	int	fd;

	(void)mlx;
	fd = open(argv[1], O_RDONLY);
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
