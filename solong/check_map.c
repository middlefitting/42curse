/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:56:51 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 16:58:45 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	minimun_size_check(int height, int width)
{
	if (height < 3 || width < 3)
		print_error_exit("MAP SIZE IS TOO SMALL");
	if (height < 4 && width < 4)
		print_error_exit("MAP SIZE IS TOO SMALL");
}

void	width_check(t_game_info *game_info)
{
	t_ull	i;

	i = 0;
	while (game_info->map[i])
	{
		if (ft_strlen(game_info->map[i]) != game_info->width)
			print_error_exit("MAP MUST BE RECTANGLE");
		i++;
	}
}

void	height_check(t_game_info *game_info)
{
	t_ull	i;

	i = 0;
	while (i < game_info->width)
	{
		if (game_info->map[game_info->height - 1][i] == '\0')
			print_error_exit("MAP MUST BE RECTANGLE");
		i++;
	}
}

void	check_map(t_game_info *game_info)
{
	minimun_size_check(game_info->height, game_info->width);
	width_check(game_info);
	height_check(game_info);
	outline_wall_check(game_info);
	contents_check(game_info);
	possible_game_check(game_info);
}
