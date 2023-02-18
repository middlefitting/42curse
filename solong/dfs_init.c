/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:56:58 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 16:59:10 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	visit_init(t_game_info *game_info, t_dfs_info *dfs_info)
{
	t_ull	i;

	i = 0;
	dfs_info->visit = calloc(game_info->height + 1, sizeof(char *));
	if (dfs_info->visit == 0)
		print_error_exit("MALLOC FAILED");
	while (i < game_info->height)
	{
		dfs_info->visit[i] = calloc(game_info->width + 1, sizeof(char));
		malloc_check(dfs_info->visit[i]);
		i++;
	}
	dfs_info->visit[game_info->loc.x][game_info->loc.y] = 1;
}

void	mv_init(t_dfs_info *dfs_info)
{
	t_ull	i;

	i = 0;
	dfs_info->mv = calloc(5, sizeof(int *));
	if (dfs_info->visit == 0)
		print_error_exit("MALLOC FAILED");
	while (i < 5)
	{
		dfs_info->mv[i] = calloc(3, sizeof(int));
		if (dfs_info->mv[i] == 0)
			print_error_exit("MALLOC FAILED");
		i++;
	}
	dfs_info->mv[0][0] = 1;
	dfs_info->mv[0][1] = 0;
	dfs_info->mv[1][0] = -1;
	dfs_info->mv[1][1] = 0;
	dfs_info->mv[2][0] = 0;
	dfs_info->mv[2][1] = 1;
	dfs_info->mv[3][0] = 0;
	dfs_info->mv[3][1] = -1;
}

void	dfs_info_init(t_game_info *game_info, t_dfs_info *dfs_info)
{
	visit_init(game_info, dfs_info);
	mv_init(dfs_info);
	dfs_info->v_collect = 0;
	dfs_info->v_exit = 0;
	dfs_info->height = game_info->height;
	dfs_info->width = game_info->width;
	dfs_info->map = game_info->map;
}
