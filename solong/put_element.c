/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:36 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 16:57:37 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game_info *game_info, void	*img_ptr, t_ull	i, t_ull j)
{
	mlx_put_image_to_window(game_info->mlx_ptr, \
							game_info->win_ptr, \
							img_ptr, \
							64 * j, \
							64 * i);
}

void	put_element(t_game_info *game_info)
{
	t_ull	i;
	t_ull	j;

	i = 0;
	while (i < game_info->height)
	{
		j = 0;
		while (j < game_info->width)
		{
			put_space(game_info, i, j);
			if (game_info->map[i][j] == '1')
				put_wall(game_info, i, j);
			else if (game_info->map[i][j] == 'C')
				put_collect(game_info, i, j);
			else if (game_info->map[i][j] == 'E')
				put_exit(game_info, i, j);
			else if (game_info->map[i][j] == 'P')
				put_character(game_info, i, j);
			j++;
		}
		i++;
	}
}
