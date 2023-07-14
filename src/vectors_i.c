/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 08:54:07 by briferre          #+#    #+#             */
/*   Updated: 2023/07/14 10:07:59 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	vector_print_i(int *v)
{
	printf("[%d, %d, %d, %d]\n", v[0], v[1], v[2], v[3]);
}

double	*vector_add_i(double *v1, double *v2)
{
	int		i;
	double	*v3;

	v3 = malloc(sizeof(double) * 4);
	i = -1;
	while (++i < 4)
		v3[i] = v1[i] + v2[i];
	return (v3);
}

double	*vector_emultiple_i(double *v1, double escalar)
{
	int		i;
	double	*v3;

	v3 = malloc(sizeof(double) * 4);
	i = -1;
	while (++i < 4)
		v3[i] = v1[i] * escalar;
	return (v3);
}

