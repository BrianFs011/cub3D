/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 08:27:09 by briferre          #+#    #+#             */
/*   Updated: 2023/08/14 16:05:08 by briferre         ###   ########.fr       */
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

int	get_tex_name(char **tex_name, char *string)
{
	int	i;

	i = 2;
	while (string[++i] && string[i] == ' ')
		;
	*tex_name = ft_substr(string, i, ft_strlen(string) - i - 1);
	if (tex_name)
		return (1);
	return (0);
}

int	get_floor_ceil(t_mlx *mlx, char *string, int floor)
{
	char	**split;
	char	*aux_string;

	aux_string = ft_substr(string, 2, ft_strlen(string));
	split = ft_split(aux_string, ',');
	if (floor)
		mlx->map.color_floor = create_trgb(0,
				ft_atoi(split[0]),
				ft_atoi(split[1]),
				ft_atoi(split[2]));
	else
		mlx->map.color_ceil = create_trgb(0,
				ft_atoi(split[0]),
				ft_atoi(split[1]),
				ft_atoi(split[2]));
	free (aux_string);
	free_split(split);
	return (1);
}

void	get_style(t_mlx *mlx)
{
	t_list	*aux;
	char	*string;
	int		check;

	check = 0;
	aux = mlx->file_loaded;
	while (aux)
	{
		string = aux->content;
		if (!ft_strncmp(string, "NO ", 3))
			check += get_tex_name(&mlx->map.tex_no, string);
		else if (!ft_strncmp(string, "SO ", 3))
			check += get_tex_name(&mlx->map.tex_so, string);
		else if (!ft_strncmp(string, "WE ", 3))
			check += get_tex_name(&mlx->map.tex_we, string);
		else if (!ft_strncmp(string, "EA ", 3))
			check += get_tex_name(&mlx->map.tex_ea, string);
		else if (!ft_strncmp(string, "F ", 2))
			check += get_floor_ceil(mlx, string, 1);
		else if (!ft_strncmp(string, "C ", 2))
			check += get_floor_ceil(mlx, string, 0);
		aux = aux->next;
	}
	if (check != 6)
		set_error(&mlx->error, "Invalid map\n");
}

void	get_map(t_mlx *mlx)
{
	int		i;
	t_list	*aux;

	i = ft_lstsize(mlx->file_loaded);
	mlx->map.matrix = malloc(sizeof(char *) * i + sizeof(char *));
	i = -1;
	aux = mlx->file_loaded;
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
}
