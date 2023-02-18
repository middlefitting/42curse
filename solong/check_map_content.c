/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:56:35 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 16:58:12 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	content_validate_check(char content)
{
	if (content != '0'
		&& content != '1'
		&& content != 'P'
		&& content != 'E'
		&& content != 'C')
		print_error_exit("CONTENT DOES NOT VALID");
}

void	count_game_content(t_game_info *game_info, t_ull i, t_ull j)
{
	if (game_info->map[i][j] == 'P')
	{
		game_info->num_of_p += 1;
		game_info->loc.x = i;
		game_info->loc.y = j;
	}
	else if (game_info->map[i][j] == 'C')
		game_info->num_of_c += 1;
	else if (game_info->map[i][j] == 'E')
		game_info->num_of_e += 1;
}

void	contents_check(t_game_info *game_info)
{
	t_ull	i;
	t_ull	j;

	i = 0;
	while (i < game_info->height)
	{
		j = 0;
		while (j < game_info->width)
		{
			content_validate_check(game_info->map[i][j]);
			count_game_content(game_info, i, j);
			j++;
		}
		i ++;
	}
	player_check(game_info);
	exit_check(game_info);
	collect_check(game_info);
}
