# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechung <sechung@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 17:17:37 by sechung           #+#    #+#              #
#    Updated: 2022/12/29 19:45:41 by sechung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME				=	server

CLIENT_NAME 			=	client

SERVER_BONUS_NAME		=	server_bonus

CLIENT_BONUS_NAME 		=	client_bonus

SERVER_FILE				=	core/server/server.c \
							core/server/server_handler.c \
							core/server/message_handler_utils.c \
							core/client/get_info.c \
							core/client/client_handler.c \
							lib/lib.c \
							lib/lib2.c \
							lib/sigaction.c

CLIENT_FILE				=	core/client/client.c \
							core/server/server_handler.c \
							core/server/message_handler_utils.c \
							core/client/get_info.c \
							core/client/client_handler.c \
							lib/lib.c \
							lib/lib2.c \
							lib/sigaction.c

SRC_DIR					=	./src
SERVER_SCRS				=	$(addprefix $(SRC_DIR)/, $(SERVER_FILE))
CLIENT_SRCS				=	$(addprefix $(SRC_DIR)/, $(CLIENT_FILE))

OBJ_DIR					=	./obj
SERVER_OBJS				=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(SERVER_FILE)))
CLIENT_OBJS				=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(CLIENT_FILE)))

LIBRARY_DIR				=	./library
CLIENT_LIB				=	$(LIBRARY_DIR)/client.a
SERVER_LIB				=	$(LIBRARY_DIR)/server.a

SRC_BONUS_DIR			=	./src_bonus
SERVER_BONUS_SCRS		=	$(addprefix $(SRC_BONUS_DIR)/, $(patsubst %.c,%_bonus.c,$(SERVER_FILE)))
CLIENT_BONUS_SRCS		=	$(addprefix $(SRC_BONUS_DIR)/, $(patsubst %.c,%_bonus.c,$(CLIENT_FILE)))

OBJ_BONUS_DIR			=	./obj_bonus
SERVER_BONUS_OBJS		=	$(addprefix $(OBJ_BONUS_DIR)/, $(patsubst %.c,%_bonus.o,$(SERVER_FILE)))
CLIENT_BONUS_OBJS		=	$(addprefix $(OBJ_BONUS_DIR)/, $(patsubst %.c,%_bonus.o,$(CLIENT_FILE)))

LIBRARY_BONUS_DIR		=	./library_bonus
CLIENT_BONUS_LIB		=	$(LIBRARY_BONUS_DIR)/client_bonus.a
SERVER_BONUS_LIB		=	$(LIBRARY_BONUS_DIR)/server_bonus.a

CFLAGS					=	-Wall -Wextra -Werror -Iinclude

all						: 	$(SERVER_NAME) $(CLIENT_NAME)

$(CLIENT_NAME)			:	 $(CLIENT_LIB)
							gcc $(CFLAGS) -o $@ $^

$(SERVER_NAME)			: 	$(SERVER_LIB)
							gcc $(CFLAGS) -o $@ $^

$(CLIENT_LIB)			:	$(CLIENT_OBJS)
							@mkdir -p $(dir $@)
							ar rc $@ $^

$(SERVER_LIB)			:	$(SERVER_OBJS)
							@mkdir -p $(dir $@)
							ar rc $@ $^

$(OBJ_DIR)/%.o			: 	$(SRC_DIR)/%.c
							@mkdir -p $(dir $@)
							$(CC) $(CFLAGS) -c $< -o $@

bonus					: 	$(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)

$(CLIENT_BONUS_NAME)	:	 $(CLIENT_BONUS_LIB)
							gcc $(CFLAGS) -o $@ $^

$(SERVER_BONUS_NAME)	: 	$(SERVER_BONUS_LIB)
							gcc $(CFLAGS) -o $@ $^

$(CLIENT_BONUS_LIB)		:	$(CLIENT_BONUS_OBJS)
							@mkdir -p $(dir $@)
							ar rc $@ $^

$(SERVER_BONUS_LIB)		:	$(SERVER_BONUS_OBJS)
							@mkdir -p $(dir $@)
							ar rc $@ $^

$(OBJ_BONUS_DIR)/%.o	: 	$(SRC_BONUS_DIR)/%.c
							@mkdir -p $(dir $@)
							$(CC) $(CFLAGS) -c $< -o $@

clean					:
							rm -rf $(OBJ_DIR) $(LIBRARY_DIR) $(OBJ_BONUS_DIR) $(LIBRARY_BONUS_DIR)

fclean					: 	clean
							rm -f $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)

re						: 	fclean all

.PHONY					: 	clean fclean all re bonus
