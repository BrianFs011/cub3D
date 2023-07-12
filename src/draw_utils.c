/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:09:49 by briferre          #+#    #+#             */
/*   Updated: 2023/07/12 07:44:39 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*vector_points_i(int p0, int p1, int p2, int p3)
{
	int	*p;

	p = malloc(sizeof(int) * 4);
	p[0] = p0;
	p[1] = p1;
	p[2] = p2;
	p[3] = p3;
	return (p);
}

double	*vector_points_d(double p0, double p1, double p2, double p3)
{
	double	*p;

	p = malloc(sizeof(double) * 4);
	p[0] = p0;
	p[1] = p1;
	p[2] = p2;
	p[3] = p3;
	return (p);
}
