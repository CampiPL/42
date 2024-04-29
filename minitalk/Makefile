# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 10:26:09 by jdepka            #+#    #+#              #
#    Updated: 2024/04/29 12:20:55 by jdepka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRC_SERVER = server.c
SRC_CLIENT = client.c
LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(SERVER) $(CLIENT) 

$(LIBFT):
	@make -s -C libft

$(SERVER): $(SRCS_SERVER) $(LIBFT)
	@$(CC) server.c -o server -Llibft -lft
	@echo "Server is ready."

$(CLIENT): $(SRCS_CLIENT) $(LIBFT)
	@$(CC) client.c -o client -Llibft -lft
	@echo "Client is ready."

clean:
	@make -C libft clean

fclean: clean
	@make fclean -s -C libft
	@$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all bonus clean fclean re
