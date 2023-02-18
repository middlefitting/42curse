/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:29 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 16:57:29 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game_info	game_info;

	arg_check(argc, argv);
	init_game_info(&game_info);
	init_map(&game_info, argv[1]);
	check_map(&game_info);
	init_game(&game_info);
	return (0);
}
