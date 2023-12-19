/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 09:48:34 by sgouzi            #+#    #+#             */
/*   Updated: 2023/12/02 09:49:01 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	we_have_a_problem(int fd, char **str)
{
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		if (str)
		{
			free(str[fd]);
			str[fd] = NULL;
		}
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[1024];
	char		*buff;
	int			bytes;

	if (we_have_a_problem(fd, str))
		return (NULL);
	buff = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(str[fd]), NULL);
	bytes = 1;
	while (!ft_strchr(str[fd], '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buff), free(str[fd]), NULL);
		buff[bytes] = '\0';
		str[fd] = ft_strjoin(str[fd], buff);
	}
	free(buff);
	if (!str[fd])
		return (free(str[fd]), NULL);
	line = ft_get_line(str[fd]);
	str[fd] = get_rest(str[fd]);
	return (line);
}
