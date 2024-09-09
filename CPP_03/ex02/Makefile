# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 19:49:52 by ubuntu            #+#    #+#              #
#    Updated: 2024/09/09 19:55:24 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fragtrap
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

FILES		= main ClapTrap ScavTrap FragTrap

SRC			= $(FILES:=.cpp)
OBJ			= $(FILES:=.o)
HEADER		= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)

clean:
	@$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re