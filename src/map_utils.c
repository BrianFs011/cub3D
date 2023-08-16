/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:23:49 by briferre          #+#    #+#             */
/*   Updated: 2023/08/16 14:25:10 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
