# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 20:07:21 by ubuntu            #+#    #+#              #
#    Updated: 2024/09/09 20:07:42 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= diamondtrap
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow
RM			= rm -rf

FILES		= main ClapTrap ScavTrap FragTrap DiamondTrap

SRC			= $(FILES:=.cpp)
OBJ			= $(FILES:=.o)
HEADER		= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)

clean:
	@$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re