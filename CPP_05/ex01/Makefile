# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 11:43:15 by jdepka            #+#    #+#              #
#    Updated: 2024/10/02 11:43:51 by jdepka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Form
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

FILES		= main Bureaucrat Form

SRC			= $(FILES:=.cpp)
OBJ			= $(FILES:=.o)
HEADER		= Bureaucrat.hpp Form.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)

clean:
	@$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re