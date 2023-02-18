/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:57:47 by sechung           #+#    #+#             */
/*   Updated: 2023/01/17 16:57:48 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

# define KEY_PRESS 2
# define RED_BUTTON_PRESS 17
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef unsigned long long	t_ull;

typedef struct s_dfs_info {
	t_ull	v_collect;
	t_ull	v_exit;
	t_ull	height;
	t_ull	width;
	char	**visit;
	int		**mv;
	char	**map;
}	t_dfs_info;

typedef struct s_loc
{
	t_ull	x;
	t_ull	y;
}	t_loc;

typedef struct s_img
{
	void	*img_ptr;
	int		height;
	int		width;
}	t_img;

typedef struct s_game_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_ull	height;
	t_ull	width;
	char	**map;
	t_ull	num_of_c;
	t_ull	num_of_e;
	t_ull	num_of_p;
	t_img	space;
	t_img	wall;
	t_img	collect;
	t_img	character;
	t_img	exit;
	t_loc	loc;
	t_ull	cnt;
	t_ull	move;
}	t_game_info;

void	print_error_exit(char *msg);
void	arg_check(int argc, char **argv);
void	malloc_check(char *str);
void	init_game_info(t_game_info *game_info);
void	init_map(t_game_info *game_info, char *arg);
void	fd_check(int fd);
void	read_check(int result);
void	size_check(int size);
void	check_map(t_game_info *game_info);
void	outline_wall_check(t_game_info *game_info);
void	contents_check(t_game_info *game_info);
void	player_check(t_game_info *game_info);
void	exit_check(t_game_info *game_info);
void	collect_check(t_game_info *game_info);
void	possible_game_check(t_game_info *game_info);
void	dfs_info_init(t_game_info *game_info, t_dfs_info *dfs_info);
void	dfs(t_dfs_info *dfs_info, t_ull x, t_ull y);
void	init_game(t_game_info *game_info);
void	set_image(t_game_info *game_info);
void	*file_to_image(char *path, t_game_info *game_info, t_img *img_info);
void	put_element(t_game_info *game_info);
void	put_image(t_game_info *game_info, void	*img_ptr, t_ull	i, t_ull j);
void	put_space(t_game_info *game_info, t_ull i, t_ull j);
void	put_wall(t_game_info *game_info, t_ull i, t_ull j);
void	put_collect(t_game_info *game_info, t_ull i, t_ull j);
void	put_exit(t_game_info *game_info, t_ull i, t_ull j);
void	put_character(t_game_info *game_info, t_ull i, t_ull j);
int		game_logic(int key, t_game_info *game_info);
void	move_logic(t_game_info *game_info, t_ull tx, t_ull ty);

#endif
