/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:02 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 16:59:29 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	v_content_check(t_dfs_info *dfs_info, t_ull x, t_ull y)
{
	if (dfs_info->map[x][y] == 'E')
		dfs_info->v_exit += 1;
	else if (dfs_info->map[x][y] == 'C')
		dfs_info->v_collect += 1;
}

int	is_outlier(t_dfs_info *dfs_info, t_ull x, t_ull y)
{
	if (x < 0
		|| x >= dfs_info->height
		|| y < 0
		|| y >= dfs_info->width)
		return (1);
	return (0);
}

int	is_visit_possible(t_dfs_info *dfs_info, t_ull x, t_ull y)
{
	if (dfs_info->visit[x][y] == 0
	&& dfs_info->map[x][y] != '1')
		return (1);
	return (0);
}

void	dfs(t_dfs_info *dfs_info, t_ull x, t_ull y)
{
	int		i;
	t_ull	tx;
	t_ull	ty;

	i = 0;
	v_content_check(dfs_info, x, y);
	while (i < 4)
	{
		tx = x + dfs_info->mv[i][0];
		ty = y + dfs_info->mv[i][1];
		if (tx >= dfs_info->height || ty >= dfs_info->width
			|| tx < 0 || ty < 0 || is_outlier(dfs_info, tx, ty) == 1)
		{
			i++;
			continue ;
		}
		if (is_visit_possible(dfs_info, tx, ty) == 1)
		{
			dfs_info->visit[tx][ty] = 1;
			dfs(dfs_info, tx, ty);
		}
		i++;
	}
}
