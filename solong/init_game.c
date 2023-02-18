/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:18 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 17:00:00 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_game_info *game_info)
{
	( void ) game_info;
	exit(0);
	return (0);
}

void	init_game(t_game_info *game_info)
{
	game_info->mlx_ptr = mlx_init();
	if (game_info->mlx_ptr == 0)
		print_error_exit("MLX CONNECT FAILED");
	game_info->win_ptr = mlx_new_window(game_info->mlx_ptr, \
										64 * (game_info->width), \
										64 * (game_info->height), \
										"so_long");
	if (game_info->win_ptr == 0)
		print_error_exit("MLX OPENING WINDOW FAILED");
	set_image(game_info);
	put_element(game_info);
	mlx_hook(game_info->win_ptr, RED_BUTTON_PRESS, 0, end_game, game_info);
	mlx_hook(game_info->win_ptr, KEY_PRESS, 0, game_logic, game_info);
	mlx_loop(game_info);
}
