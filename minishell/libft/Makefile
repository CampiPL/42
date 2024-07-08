# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 02:28:07 by rmakhlou          #+#    #+#              #
#    Updated: 2024/07/08 20:16:47 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_atoi.c 	\
			ft_atol.c 	\
			ft_atoul.c 	\
			ft_bzero.c 	\
			ft_calloc.c 	\
			ft_cntwrd.c	\
			ft_freedom.c	\
			ft_isalnum.c 	\
			ft_isalpha.c 	\
			ft_isup.c 	\
			ft_islow.c 	\
			ft_isascii.c 	\
			ft_isdigit.c 	\
			ft_isprint.c 	\
			ft_isspace.c 	\
			ft_itoa.c 	\
			ft_lstlen.c 	\
			ft_ltoa.c 	\
			ft_memchr.c 	\
			ft_memcmp.c 	\
			ft_memcpy.c 	\
			ft_memmove.c 	\
			ft_memset.c 	\
			ft_printf.c	\
			ft_putchar_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c 	\
			ft_putstr_fd.c 	\
			ft_split.c 	\
			ft_strchr.c 	\
			ft_strdup.c 	\
			ft_striteri.c 	\
			ft_strjoin.c 	\
			ft_strlcat.c 	\
			ft_strlcpy.c 	\
			ft_strlen.c 	\
			ft_skipchar.c 	\
			ft_strlenstr.c 	\
			ft_strmapi.c 	\
			ft_strncmp.c 	\
			ft_strcmp.c 	\
			ft_strnstr.c 	\
			ft_strrchr.c 	\
			ft_strtrim.c 	\
			ft_substr.c 	\
			ft_tolower.c 	\
			ft_toupper.c	\
			ft_ultoa_b.c 	\
			get_next_line.c	

OBJ = ${SRC:.c=.o}

CC = cc

FLAGS = -Wall -Wextra -Werror -g

AR = ar -cr

RM = rm -f

NAME = libft.a

all: ${NAME}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${AR}  ${NAME} ${OBJ}

clean:
	${RM} ${OBJ}

fclean:    clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
