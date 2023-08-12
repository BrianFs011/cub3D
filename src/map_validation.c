/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:23:38 by sde-cama          #+#    #+#             */
/*   Updated: 2023/08/12 13:06:57 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	validate_args(int argc, char **argv)
{
	int	offset;

	if (argc != 2)
		exit_error("Invalid number of arguments. Correct usage: ./cub3D <map_address>");
	offset = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".cub", argv[1] + offset, 5) != 0)
		exit_error("Invalid type of map file. Map file must be .cub");
}
