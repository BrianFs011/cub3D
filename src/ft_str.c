/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:40:35 by briferre          #+#    #+#             */
/*   Updated: 2023/08/12 14:33:04 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strcpy(char *src, int src_free)
{
	int			i;
	int			src_size;
	char		*dest;

	src_size = ft_strlen(src);
	dest = malloc(sizeof(char) * src_size + sizeof(char));
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	if (src_free)
		free(src);
	return (dest);
}
