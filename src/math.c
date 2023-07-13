/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:31:26 by briferre          #+#    #+#             */
/*   Updated: 2023/07/13 08:18:19 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	degrees_to_radians(double degree)
{
	return (PI * degree / 180);
}

double	ray_multiple(int i)
{
	return (2 * ((double)i / (double)WIDTH) - 1);
}

double	ray_to_plane(double direction, double plane, double multiple)
{
	double	r;

	r = direction + (plane * multiple);
	return (r);
}

double	magnitude(int delta_x, int delta_y)
{
	return (sqrt(pow(delta_x, 2) + pow(delta_y, 2)));
}
