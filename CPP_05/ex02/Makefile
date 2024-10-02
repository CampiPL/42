# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 11:56:34 by jdepka            #+#    #+#              #
#    Updated: 2024/10/02 11:58:33 by jdepka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Forms
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

FILES		= main Bureaucrat Form PresidentialPardonForm RobotomyRequestForm ShrubberyCreationForm

SRC			= $(FILES:=.cpp)
OBJ			= $(FILES:=.o)
HEADER		= Bureaucrat.hpp Form.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)

clean:
	@$(RM) $(OBJDIR) $(OBJ) ShrubberyCreationForm_shrubbery

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re