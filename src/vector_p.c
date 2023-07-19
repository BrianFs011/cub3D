/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:26:29 by briferre          #+#    #+#             */
/*   Updated: 2023/07/18 21:04:53 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_points	vector_init(double p0, double p1, double p2, double p3)
{
	t_points	p;

	p.x = p0;
	p.y = p1;
	p.x1 = p2;
	p.y1 = p3;
	return (p);
}

t_points	vector_rotate_p(t_points p, double angle)
{
	t_points	r;

	r.x = p.x * cos(degrees_to_radians(angle));
	r.x += p.y * sin(degrees_to_radians(angle));
	r.y = p.x * -sin(degrees_to_radians(angle));
	r.y += p.y * cos(degrees_to_radians(angle));
	return (r);
}

t_points	vector_emultiple(t_points v, double escalar)
{
	t_points	r;

	r.x = v.x * escalar;
	r.y = v.y * escalar;
	r.x1 = v.x1 * escalar;
	r.y1 = v.y1 * escalar;
	return (r);
}

t_points	vector_add(t_points v1, t_points v2)
{
	t_points	v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	v3.x1 = v1.x1 + v2.x1;
	v3.y1 = v1.y1 + v2.y1;
	return (v3);
}
