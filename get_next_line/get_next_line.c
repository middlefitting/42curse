/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:38:54 by sechung           #+#    #+#             */
/*   Updated: 2022/07/16 16:38:43 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*if_enter(char **buf, char **line, char *find_enter)
{
	char	*temp;

	*line = ft_strndup(*buf, find_enter - (*buf) + 1);
	if (*line == 0)
	{
		free(buf);
		return (0);
	}
	temp = ft_strndup(find_enter + 1, ft_strlen(find_enter + 1));
	free(*buf);
	*buf = temp;
	if (temp == 0)
	{
		free(*line);
		return (0);
	}
	return (*line);
}

static char	*return_line(char **buf, char **line)
{
	char	*find_enter;

	if (*buf == 0)
		return (0);
	if (**buf == 0)
	{
		free(*buf);
		return (0);
	}
	find_enter = ft_strchr(*buf, '\n');
	if (!find_enter)
	{
		*line = *buf;
		*buf = 0;
		return (*line);
	}
	return (if_enter(buf, line, find_enter));
}

char	*get_next_line(int fd)
{
	static char	*save_buffer[OPEN_MAX];
	char		temp_buffer[BUFFER_SIZE + 1];
	long		read_size;
	char		*line;

	if (fd > OPEN_MAX || read(fd, temp_buffer, 0) == -1 || BUFFER_SIZE <= 0)
		return (0);
	if (ft_strchr(save_buffer[fd], '\n'))
		return (return_line(&save_buffer[fd], &line));
	read_size = read(fd, temp_buffer, BUFFER_SIZE);
	while (read_size > 0)
	{
		temp_buffer[read_size] = 0;
		save_buffer[fd] = ft_strjoin(save_buffer[fd], temp_buffer);
		if (save_buffer[fd] == 0)
			return (0);
		if (ft_strchr(&temp_buffer[fd], '\n'))
			return (return_line(&save_buffer[fd], &line));
		read_size = read(fd, temp_buffer, BUFFER_SIZE);
	}
	return (return_line(&save_buffer[fd], &line));
}
