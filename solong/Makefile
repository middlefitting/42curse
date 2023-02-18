# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechung <sechung@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 16:57:32 by sechung           #+#    #+#              #
#    Updated: 2023/01/18 15:09:07 by sechung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

LIB_DIR		=	./libft
LIBFT		=	libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

DBGS		=	-fsanitize=address -g3

MLX_DIR		=	./mlx
MLX_FLAGS	=	-framework OpenGL -framework Appkit

SRCS		=	main.c \
				common.c \
				arg_check.c \
				init_game_info.c \
				init_map.c \
				init_map2.c \
				check_map.c \
				check_map_wall.c \
				check_map_content.c \
				check_map_content2.c \
				check_map_possible.c \
				dfs_init.c \
				dfs.c \
				set_image.c \
				put_element.c \
				put_element2.c \
				game_logic.c \
				game_logic2.c \
				init_game.c

OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(MLX_DIR) -lmlx $(MLX_FLAGS) $(LIB_DIR)/$(LIBFT)

clean:
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY = all clean fclean re
