/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:14 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 16:57:15 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_info(t_game_info *game_info)
{
	game_info->num_of_c = 0;
	game_info->num_of_e = 0;
	game_info->num_of_p = 0;
	game_info->cnt = 0;
	game_info->move = 0;
}
