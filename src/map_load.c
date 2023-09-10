/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 08:27:09 by briferre          #+#    #+#             */
/*   Updated: 2023/09/10 19:22:04 by sde-cama         ###   ########.fr       */
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

int	check_value(void *value)
{
	char	*string;
	int		i;

	string = value;
	if (!string || string[0] == '\n')
		return (0);
	i = -1;
	while (string[++i] && string[i] != '\n')
	{
		if (!(string[i] == '1' || string[i] == '0' || string[i] == 'N'
				|| string[i] == 'W' || string[i] == 'S' ||string[i] == 'E'
				|| string[i] == ' '))
			return (0);
	}
	return (1);
}

void	read_map(t_mlx *mlx)
{
	int		i;
	int		size;
	t_list	*aux;

	size = ft_lstsize(mlx->file_loaded);
	mlx->map.matrix = malloc(sizeof(char *) * size + sizeof(char *));
	i = -1;
	aux = find_map_position(mlx->file_loaded);
	mlx->camera.position = find_personage(aux->content,
			mlx->camera.position, i);
	while (aux)
	{
		if (check_value(aux->content))
		{
			mlx->map.matrix[++i] = aux->content;
			mlx->camera.position = find_personage(aux->content,
					mlx->camera.position, i);
		}
		aux = aux->next;
	}
	while (++i < size + 1)
		mlx->map.matrix[i] = NULL;
	if (check_map(mlx) || check_map_vertically(mlx))
		exit_error(mlx->error.error_message, mlx);
}

void	get_map(t_mlx *mlx, char **argv)
{
	get_file(mlx, argv);
	get_style(mlx);
	read_map(mlx);
}
