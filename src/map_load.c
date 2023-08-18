/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 08:27:09 by briferre          #+#    #+#             */
/*   Updated: 2023/08/17 22:28:12 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_points	find_personage(char *string, t_points cp, int i)
{
	t_points	p;
	int			j;

	j = -1;
	p.x = cp.x;
	p.y = cp.y;
	// printf("%s\n", string);
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

void	get_map(t_mlx *mlx)
{
	int		i;
	t_list	*aux;

	i = ft_lstsize(mlx->file_loaded);
	mlx->map_height = ft_lstsize(mlx->file_loaded);
	mlx->map = malloc(sizeof(char *) * i + sizeof(char *));
	i = -1;
	aux = mlx->file_loaded;
	mlx->camera.position = find_personage(aux->content,
			mlx->camera.position, i);
	while (aux && aux->next)
	{
		mlx->map[++i] = aux->content;
		mlx->camera.position = find_personage(aux->content,
				mlx->camera.position, i);
		aux = aux->next;
	}
	mlx->map[++i] = NULL;
	if (check_map(mlx) || check_map_vertically(mlx))
		clear_memory_map(mlx);
}

void	get_file(t_mlx *mlx, char **argv)
{
	int		fd;
	char	*string;

	(void)mlx;
	(void)string;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error(FD_ERROR);
	string = get_next_line(fd);
	mlx->file_loaded = ft_lstnew(string);
	while (string)
	{
		// printf("%s", string);
		string = get_next_line(fd);
		ft_lstadd_back(&mlx->file_loaded, ft_lstnew(string));
	}
	close(fd);
}

void	get_style(t_mlx *mlx)
{
	t_list	*aux;
	char	*string;
	int		check;

	check = 0;
	aux = mlx->file_loaded;
	while (aux && aux->next && check < 21)
	{
		string = mlx->file_loaded->content;
		printf("%s", string);
		if (!ft_strncmp(string, "NO", 2))
		{
			check += 1;
		}
		else if (!ft_strncmp(string, "SO", 2))
		{
			check += 2;
			// printf("%s\n", string);
		}
		else if (!ft_strncmp(string, "WE", 2))
		{
			check += 3;
			// printf("%s\n", string);
		}
		else if (!ft_strncmp(string, "EA", 2))
		{
			check += 4;
			// printf("%s\n", string);
		}
		else if (!ft_strncmp(string, "F ", 2))
		{
			check += 5;
			string = ft_substr(string, 2, ft_strlen(string));
			char **split = ft_split(string, ',');
			mlx->camera.color_floor = create_trgb(0, ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
			// printf("%d %d\n", mlx->camera.color_floor, create_trgb(0, 220, 100, 0));
		}
		else if (!ft_strncmp(string, "C ", 2))
		{
			check += 6;
			string = ft_substr(string, 2, ft_strlen(string));
			char **split = ft_split(string, ',');
			mlx->camera.color_floor = create_trgb(0, ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
		}
		aux = mlx->file_loaded;
		mlx->file_loaded = mlx->file_loaded->next;
		free(aux);
		// printf("%s\n", (char *)aux->content);
	}
	if (check != 21)
		mlx->error.error = 1;
}

// void	map_load(t_mlx *mlx, char **argv)
// {

// 	(void)mlx;
// 	(void)argv;
// 	// get_map(mlx, fd);
// }

void	clear_memory_map(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < mlx->map_size && mlx->map[i])
		free(mlx->map[i]);
	free(mlx->map);
}
