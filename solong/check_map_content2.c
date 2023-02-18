/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:56:40 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 16:56:41 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_check(t_game_info *game_info)
{
	if (game_info->num_of_p != 1)
		print_error_exit("PLAYER MUST BE ONE");
}

void	exit_check(t_game_info *game_info)
{
	if (game_info->num_of_e != 1)
		print_error_exit("EXIT MUST BE ONE");
}

void	collect_check(t_game_info *game_info)
{
	if (game_info->num_of_c < 1)
		print_error_exit("COLLECT MUST BE LEAST ONE");
}
