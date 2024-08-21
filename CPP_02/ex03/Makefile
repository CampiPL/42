# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 19:05:52 by jdepka            #+#    #+#              #
#    Updated: 2024/08/21 19:06:17 by jdepka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Fixed
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

FILES		= main Fixed Point bsp

SRC			= $(FILES:=.cpp)
OBJ			= $(FILES:=.o)
HEADER		= Fixed.hpp Point.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re