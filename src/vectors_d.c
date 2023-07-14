/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 08:54:07 by briferre          #+#    #+#             */
/*   Updated: 2023/07/14 13:53:53 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	vector_print_d(double *v)
{
	printf("[%lf, %lf, %lf, %lf]\n", v[0], v[1], v[2], v[3]);
}

double	*vector_add_d(double *v1, double *v2)
{
	int		i;
	double	*v3;

	v3 = malloc(sizeof(double) * 4);
	i = -1;
	while (++i < 4)
		v3[i] = v1[i] + v2[i];
	return (v3);
}

double	*vector_emultiple_d(double *v1, double escalar)
{
	int		i;
	double	*v3;

	v3 = malloc(sizeof(double) * 4);
	i = -1;
	while (++i < 4)
		v3[i] = v1[i] * escalar;
	return (v3);
}

double	*vector_rotate(double *v, double angle)
{
	double *r;

	r = malloc(sizeof(double) * 4);
	r[0] = cos(degrees_to_radians(angle)) * v[0] + sin(degrees_to_radians(angle)) * v[1];
	r[1] = -sin(degrees_to_radians(angle)) * v[0] + cos(degrees_to_radians(angle)) * v[1];
	return (r);
}
