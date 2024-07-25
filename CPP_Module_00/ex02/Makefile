# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 18:57:21 by ubuntu            #+#    #+#              #
#    Updated: 2024/07/25 19:21:03 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Account
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

FILES		= test Account

SRC			= $(FILES:=.cpp)
OBJ			= $(FILES:=.o)
HEADER		= Account.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re