/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:06 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 16:57:07 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	next_x(int key, t_game_info *game_info)
{
	t_ull	tx;

	tx = game_info->loc.x;
	if (key == W)
		tx -= 1;
	if (key == S)
		tx += 1;
	return (tx);
}

int	next_y(int key, t_game_info *game_info)
{
	t_ull	ty;

	ty = game_info->loc.y;
	if (key == D)
		ty += 1;
	if (key == A)
		ty -= 1;
	return (ty);
}

int	game_logic(int key, t_game_info *game_info)
{
	t_ull	tx;
	t_ull	ty;

	if (key == ESC)
		exit(0);
	else if (key == W || key == A || key == S || key == D)
	{
		game_info->move += 1;
		ft_putnbr_fd(game_info->move, 0);
		ft_putchar_fd('\n', 1);
		tx = next_x(key, game_info);
		ty = next_y(key, game_info);
		move_logic(game_info, tx, ty);
	}
	return (0);
}
