/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_possible.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:56:43 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 16:58:24 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_compare(t_dfs_info *dfs_info, t_game_info *game_info)
{
	if (dfs_info->v_collect != game_info->num_of_c
		|| dfs_info->v_exit != game_info->num_of_e)
		print_error_exit("GAME CLEAR IMPOSSIBLE");
}

void	free_t_dfs(t_dfs_info *dfs_info)
{
	t_ull	i;

	i = 0;
	while (i <= dfs_info->height)
		free(dfs_info->visit[i++]);
	free(dfs_info->visit);
	dfs_info->visit = 0;
	i = 0;
	while (i <= 4)
		free(dfs_info->mv[i++]);
	free(dfs_info->mv);
	dfs_info->mv = 0;
}

void	possible_game_check(t_game_info *game_info)
{
	t_dfs_info	dfs_info;

	dfs_info_init(game_info, &dfs_info);
	dfs(&dfs_info, game_info->loc.x, game_info->loc.y);
	count_compare(&dfs_info, game_info);
	free_t_dfs(&dfs_info);
}
