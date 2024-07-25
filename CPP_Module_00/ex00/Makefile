# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 17:47:58 by ubuntu            #+#    #+#              #
#    Updated: 2024/07/25 17:48:47 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

all: $(NAME)

$(NAME): 
	@$(CC) $(FLAGS) megaphone.cpp -o $(NAME)

clean:
	@$(RM) $(NAME)

fclean:
	@$(RM) $(NAME)

re: clean all

.PHONY: all clean re