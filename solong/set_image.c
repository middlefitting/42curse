/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:44 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 17:01:21 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*file_to_image(char *path, t_game_info *game_info, t_img *img_info)
{
	void	*result;

	result = mlx_xpm_file_to_image(game_info->mlx_ptr, \
						path, \
						&(img_info->width), \
						&(img_info->height));
	if (result == 0)
		print_error_exit("FAIL FOR FILE TO IMAGE");
	return (result);
}

void	set_image(t_game_info *game_info)
{
	game_info->space.img_ptr = file_to_image("imgs/space.xpm", \
											game_info, &(game_info->space));
	game_info->wall.img_ptr = file_to_image("imgs/wall.xpm", game_info, \
											&(game_info->wall));
	game_info->collect.img_ptr = file_to_image("imgs/collect.xpm", game_info, \
											&(game_info->collect));
	game_info->exit.img_ptr = file_to_image("imgs/exit.xpm", game_info, \
											&(game_info->exit));
	game_info->character.img_ptr = file_to_image("imgs/character.xpm", \
											game_info, &(game_info->character));
}
