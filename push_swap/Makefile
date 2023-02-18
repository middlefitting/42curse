# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechung <sechung@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 16:29:24 by sechung           #+#    #+#              #
#    Updated: 2023/01/29 16:31:32 by sechung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	push_swap

FILE					=	main.c \
							sys_call.c \
							arg_check.c \
							ft_free.c \
							make_arr.c \
							make_stack.c \
							arr_util.c \
							push_swap.c \
							rrx_logic.c \
							rx_logic.c \
							px_logic.c \
							sx_logic.c \
							pivot_logic.c \
							greedy.c \
							find_ma.c \
							push_swap_utils.c


SRC_DIR					=	./src
SCRS					=	$(addprefix $(SRC_DIR)/, $(FILE))

OBJ_DIR					=	./obj
OBJS					=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(FILE)))

LIBFT					=	libft

CC						=	cc
CFLAGS					=	-Wall -Wextra -Werror -Iinclude

all						: 	$(NAME)

$(NAME)					:	$(OBJS)
							make -C $(LIBFT)
							$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT) -lft

$(OBJ_DIR)/%.o			: 	$(SRC_DIR)/%.c
							@mkdir -p $(dir $@)
							$(CC) $(CFLAGS) -c $< -o $@

clean					:
							make clean -C $(LIBFT)
							rm -rf $(OBJ_DIR)

fclean					:	clean
							make fclean -C $(LIBFT)
							rm -rf $(NAME)

re						: 	fclean all

.PHONY					: 	clean fclean all re
