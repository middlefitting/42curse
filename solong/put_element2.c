/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_element2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:40 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 16:57:41 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_space(t_game_info *game_info, t_ull i, t_ull j)
{
	put_image(game_info, game_info->space.img_ptr, i, j);
}

void	put_wall(t_game_info *game_info, t_ull i, t_ull j)
{
	put_image(game_info, game_info->wall.img_ptr, i, j);
}

void	put_collect(t_game_info *game_info, t_ull i, t_ull j)
{
	put_image(game_info, game_info->collect.img_ptr, i, j);
}

void	put_exit(t_game_info *game_info, t_ull i, t_ull j)
{
	put_image(game_info, game_info->exit.img_ptr, i, j);
}

void	put_character(t_game_info *game_info, t_ull i, t_ull j)
{
	put_image(game_info, game_info->character.img_ptr, i, j);
}
