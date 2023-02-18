/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:56:46 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 16:56:47 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	row_wall_check(t_game_info *game_info)
{
	t_ull	i;

	i = 0;
	while (i < game_info->width)
	{
		if (game_info->map[0][i] != '1'
		|| game_info->map[game_info->height - 1][i] != '1')
			print_error_exit("MAP DOES NOT SURROUND BY THE WALL");
		i++;
	}
}

void	column_wall_check(t_game_info *game_info)
{
	t_ull	i;

	i = 0;
	while (i < game_info->height)
	{
		if (game_info->map[i][0] != '1'
		|| game_info->map[i][game_info->width - 1] != '1')
			print_error_exit("MAP DOES NOT SURROUND BY THE WALL");
		i++;
	}
}

void	outline_wall_check(t_game_info *game_info)
{
	row_wall_check(game_info);
	column_wall_check(game_info);
}
