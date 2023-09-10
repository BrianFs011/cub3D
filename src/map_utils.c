/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:23:49 by briferre          #+#    #+#             */
/*   Updated: 2023/09/10 08:09:10 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_floor_ceil(t_mlx *mlx, char *string, int floor)
{
	char	**split;
	char	*aux_string;
	int		rgb[3];
	int		r;

	aux_string = ft_substr(string, 2, ft_strlen(string));
	split = ft_split(aux_string, ',');
	rgb[0] = ft_atoi(split[0]);
	rgb[1] = ft_atoi(split[1]);
	rgb[2] = ft_atoi(split[2]);
	r = check_rgb(rgb);
	if (r)
	{
		if (floor)
			mlx->map.color_floor = create_trgb(0, rgb[0], rgb[1], rgb[2]);
		else
			mlx->map.color_ceil = create_trgb(0, rgb[0], rgb[1], rgb[2]);
	}
	free (aux_string);
	free_split(split);
	return (r);
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

int	check_rgb(int rgb[3])
{
	int	i;

	i = -1;
	while (++i < 3)
		if (rgb[i] < 0 || rgb[i] > 255)
			return (0);
	return (1);
}
