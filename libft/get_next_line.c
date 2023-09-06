/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:57:13 by mgama             #+#    #+#             */
/*   Updated: 2023/09/06 17:15:06 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_file(int fd, char *file)
{
	char	*buff;
	int		read_bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(file, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		file = ft_strjoin(file, buff);
	}
	free(buff);
	return (file);
}

char	*get_next_line(int fd)
{
	static char	*file = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(file), file = NULL, NULL);
	file = ft_read_file(fd, file);
	if (!file)
	{
		free(file);
		return (NULL);
	}
	line = ft_get_line(file);
	file = slice_file(file);
	return (line);
}
