/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_style.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 03:17:48 by sde-cama          #+#    #+#             */
/*   Updated: 2023/08/21 03:18:03 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_tex_name(char **tex_name, char *string)
{
	int	i;

	i = 2;
	while (string[++i] && string[i] == ' ')
		;
	if (*tex_name)
		free(*tex_name);
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
		exit_error(MAP_STYLE_ERROR, mlx);
}
