/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:04:49 by briferre          #+#    #+#             */
/*   Updated: 2023/08/12 14:32:59 by briferre         ###   ########.fr       */
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
