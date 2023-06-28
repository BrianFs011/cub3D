/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briferre <briferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:43:03 by briferre          #+#    #+#             */
/*   Updated: 2022/07/16 13:21:12 by briferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	int			size_line;
	char		*line;
	static char	*buf;

	line = NULL;
	i = 0;
	size_line = 1;
	buf = (char *)malloc((sizeof(char) * 1));
	while (fd != -1)
	{
		buf[0] = ' ';
		if (read(fd, buf, 1) == 1)
			line = ft_insert(line, buf[0], &i, &size_line);
		else
			fd = -1;
		if (*buf && buf[0] == '\n')
			fd = -1;
	}
	free(buf);
	ft_null_end(line, i, size_line);
	return (line);
}
