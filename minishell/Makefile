# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakhlou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 10:29:43 by rmakhlou          #+#    #+#              #
#    Updated: 2024/06/14 16:22:24 by rmakhlou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	minishell.c	\
		ft_signal.c	\
		ft_strsimp.c	\
		ft_verifcote.c	\
		ft_verifwarg.c	\
		ft_verifpip.c	\
		ft_verifredir.c	\
#		ft_redir.c	#

OBJ = ${SRC:.c=.o}

CC = cc

FLAGS = -Wall -Werror -Wextra -g

READLINE = -lreadline

RM = rm -rf

NAME = Minishell

LIBS = libft/libft.a 

all: ${NAME}

${LIBS}:
		make -C libft
.c.o:
	${CC} ${FLAGS} -c $< -o $@

${NAME}:${OBJ} ${LIBS}
	${CC} ${OBJ} -o ${NAME} ${LIBS} ${READLINE}

clean:
	${RM} ${OBJ}; make -C libft clean

fclean:	clean
	${RM} ${NAME} ${LIBS}

re: fclean all

.PHONY: all clean fclean re

