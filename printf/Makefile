# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechung <sechung@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 15:24:49 by sechung           #+#    #+#              #
#    Updated: 2022/07/20 19:48:28 by sechung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c \
			flag_initialize.c \
			parse.c \
			box_initialize.c \
			print_logic.c \
			utils.c \

OBJS		=	$(SRCS:.c=.o)

NAME		=	libftprintf.a
RM			=	rm -f
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

$(NAME)		:	$(OBJS)
			ar rc $@ $^

.c.o		:
			$(CC) $(CFLAGS) -c $< -o $@ -I./

all			:	$(NAME)

clean		:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean		:	clean
			$(RM) $(NAME)

re			:	
			make fclean
			make all

.PHONY		:	all clean fclean re
