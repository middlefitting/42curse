/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:22 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 17:00:15 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_size(int fd)
{
	int		i;
	int		size;
	char	temp[4096];

	i = 1;
	size = 0;
	while (i != 0)
	{
		i = read(fd, temp, 4096);
		read_check(i);
		size += i;
	}
	size_check(size);
	return (size);
}

int	get_file_size(char *filename)
{
	int		fd;
	int		size;

	fd = open(filename, O_RDONLY);
	fd_check(fd);
	size = get_size(fd);
	close(fd);
	return (size);
}

char	*read_file(char *filename)
{
	int		fd;
	int		size;
	char	*buffer;

	size = get_file_size(filename);
	buffer = (char *)calloc(size + 1, sizeof(char));
	malloc_check(buffer);
	fd = open(filename, O_RDONLY);
	fd_check(fd);
	read_check(read(fd, buffer, size));
	close(fd);
	return (buffer);
}

void	init_map_size(t_game_info *game_info)
{
	t_ull	i;

	i = 0;
	while (game_info->map[i])
		i++;
	game_info->height = i;
	game_info->width = ft_strlen(game_info->map[0]);
}

void	init_map(t_game_info *game_info, char *arg)
{
	char		*buffer;

	buffer = read_file(arg);
	game_info->map = ft_split(buffer, '\n');
	free(buffer);
	if (game_info->map == 0)
		print_error_exit("MALLOC FAILED");
	init_map_size(game_info);
}
