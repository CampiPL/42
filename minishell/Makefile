# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 10:29:43 by rmakhlou          #+#    #+#              #
#    Updated: 2024/07/14 17:03:31 by jdepka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	minishell.c	\
		ft_signal.c	\
		ft_strsimp.c	\
		ft_verifcote.c	\
		ft_verifwarg.c	\
		ft_verifpip.c	\
		ft_verifredir.c	\
		ft_penv.c	\
		ft_splitpip.c	\
		ft_convarg.c	\
		ft_clean.c	\
		ft_prep.c	\
		ft_geterrno.c	\
		mini.c	\
		utils.c	\
		types.c	\
		redirexec.c	\
		free.c	\
		exec.c	\
		bin.c	\
		fd.c	\
		builtin.c	\
		echo.c	\
		pwd.c	\
		cd.c	\
		env.c	\
		ft_envcpy.c	\
		export.c	\
		unset.c	\
		redir.c	\
		heredoc.c	\
		path.c

OBJ = ${SRC:.c=.o}

CC = cc

FLAGS = -Wall -Werror -Wextra -g

READLINE = -lreadline

RM = rm -rf

NAME = minishell

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

