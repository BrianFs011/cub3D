/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:04:49 by briferre          #+#    #+#             */
/*   Updated: 2023/08/25 02:50:09 by sde-cama         ###   ########.fr       */
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

enum e_cardinal	ternary_e(int condition, enum e_cardinal a, enum e_cardinal b)
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

int	set_error_msg(t_mlx *mlx, char *error_msg)
{
	mlx->error.type = 1;
	mlx->error.error_message = error_msg;
	return (1);
}
