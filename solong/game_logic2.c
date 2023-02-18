/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:09 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 16:59:43 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_position(t_game_info *game_info, t_ull tx, t_ull ty)
{
	game_info->loc.x = tx;
	game_info->loc.y = ty;
}

void	check_collect(t_game_info *game_info, t_ull i, t_ull j)
{
	if (game_info->map[i][j] == 'C')
	{
		game_info->cnt += 1;
		game_info->map[i][j] = '0';
		put_space(game_info, i, j);
		put_character(game_info, i, j);
	}
}

void	check_finish(t_game_info *game_info, t_ull i, t_ull j)
{
	if (game_info->map[i][j] == 'E' && game_info->cnt == game_info->num_of_c)
	{
		ft_putstr_fd("GAME FINISH!\n", 1);
		exit(0);
	}
}

void	move_logic(t_game_info *game_info, t_ull tx, t_ull ty)
{
	if (game_info->map[tx][ty] == '1')
		return ;
	put_space(game_info, game_info->loc.x, game_info->loc.y);
	if (game_info->map[game_info->loc.x][game_info->loc.y] == 'E')
		put_exit(game_info, game_info->loc.x, game_info->loc.y);
	put_character(game_info, tx, ty);
	set_position(game_info, tx, ty);
	check_collect(game_info, tx, ty);
	check_finish(game_info, tx, ty);
}
