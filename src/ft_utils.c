/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:04:49 by briferre          #+#    #+#             */
/*   Updated: 2023/08/12 12:22:50 by sde-cama         ###   ########.fr       */
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

int	print_msg(char *str, char *detail, int exit_nb)
{
	if (!detail)
		printf("%s\n", str);
	else
		printf("%s%s\n", str, detail);
	return (exit_nb);
}
