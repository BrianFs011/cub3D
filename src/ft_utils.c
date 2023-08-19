/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:04:49 by briferre          #+#    #+#             */
/*   Updated: 2023/08/19 03:45:38 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ternary_int(int condition, int a, int b)
{
	if (condition)
		return (a);
	return (b);
}

double	ternary_d(int condition, double a, double b)
{
	if (condition)
		return (a);
	return (b);
}

void	free_split(char **string)
{
	int	i;

	if (!string)
		return ;
	i = -1;
	while (string[++i])
		free(string[i]);
	free(string);
}

void	del(void *d)
{
	char	*string;

	(void)d;
	string = d;
	free(string);
}

void	exit_error(char *error, t_mlx *mlx)
{
	if (mlx)
	{
		ft_lstclear(&mlx->file_loaded, del);
		free(mlx->map.tex_ea);
		free(mlx->map.tex_no);
		free(mlx->map.tex_so);
		free(mlx->map.tex_we);
		if (mlx->map.matrix != NULL)
			free(mlx->map.matrix);
	}
	ft_putendl_fd(error, 2);
	exit(0);
}

int	set_error_msg(t_mlx *mlx, char *error_msg)
{
	mlx->error.type = 1;
	mlx->error.error_message = error_msg;
	return (1);
}
