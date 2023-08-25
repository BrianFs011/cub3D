/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 08:27:09 by briferre          #+#    #+#             */
/*   Updated: 2023/08/24 21:13:01 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_file(t_mlx *mlx, char **argv)
{
	int		fd;
	char	*string;

	(void)mlx;
	(void)string;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error(FD_ERROR, NULL);
	string = get_next_line(fd);
	ft_lstadd_back(&mlx->file_loaded, ft_lstnew(string));
	while (string)
	{
		string = get_next_line(fd);
		if (string)
			ft_lstadd_back(&mlx->file_loaded, ft_lstnew(string));
	}
	close(fd);
}

t_list	*find_map_position(t_list *file_loaded)
{
	char	*string;
	int		check;

	check = 0;
	while (file_loaded && check < 6)
	{
		string = file_loaded->content;
		if (!ft_strncmp(string, "NO ", 3) || \
			!ft_strncmp(string, "SO ", 3) || \
			!ft_strncmp(string, "WE ", 3) || \
			!ft_strncmp(string, "EA ", 3) || \
			!ft_strncmp(string, "F ", 2) || \
			!ft_strncmp(string, "C ", 2))
			check += 1;
		file_loaded = file_loaded->next;
	}
	while (file_loaded)
	{
		string = file_loaded->content;
		if (ft_strchr(string, '0') || ft_strchr(string, '1'))
			break ;
		file_loaded = file_loaded->next;
	}
	return (file_loaded);
}

void	read_map(t_mlx *mlx)
{
	int		i;
	t_list	*aux;

	i = ft_lstsize(mlx->file_loaded);
	mlx->map.matrix = malloc(sizeof(char *) * i + sizeof(char *));
	i = -1;
	aux = find_map_position(mlx->file_loaded);
	mlx->camera.position = find_personage(aux->content,
			mlx->camera.position, i);
	while (aux)
	{
		mlx->map.matrix[++i] = aux->content;
		mlx->camera.position = find_personage(aux->content,
				mlx->camera.position, i);
		aux = aux->next;
	}
	mlx->map.matrix[++i] = NULL;
	if (check_map(mlx) || check_map_vertically(mlx))
		exit_error(mlx->error.error_message, mlx);
}

void	get_map(t_mlx *mlx, char **argv)
{
	get_file(mlx, argv);
	get_style(mlx);
	read_map(mlx);
}
