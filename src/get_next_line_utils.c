/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:07:06 by briferre          #+#    #+#             */
/*   Updated: 2023/09/13 23:59:53 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

void	ft_cpy(char *dest, char *src, int size_line)
{
	int	i;

	i = 0;
	while (i < (size_line / 2))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < size_line)
	{
		dest[i] = 0;
		i++;
	}
}

char	*ft_insert(char *line, char word, int *i, int *size_line)
{
	char	*new_line;

	new_line = NULL;
	if ((*size_line) == 1)
	{
		(*size_line)++;
		new_line = (char *)malloc((sizeof(char) * (*size_line)) + 1);
		new_line[(*i)] = word;
	}
	else if ((*i) == (*size_line))
	{
		(*size_line) *= 2;
		new_line = (char *)malloc((sizeof(char) * (*size_line)) + 1);
		ft_cpy(new_line, line, (*size_line));
		new_line[*i] = word;
		new_line[(*size_line)] = '\0';
		free(line);
	}
	else
	{
		line[(*i)] = word;
		new_line = line;
	}
	(*i)++;
	return (new_line);
}

void	ft_null_end(char *line, int i, int size_line)
{
	if (i > 0)
	{
		line[i] = '\0';
		while (++i < size_line)
		{
			if (line[i])
			{
				line[i] = '\0';
			}
		}
	}
}
