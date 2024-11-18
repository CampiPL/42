# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 20:57:06 by jdepka            #+#    #+#              #
#    Updated: 2024/11/18 21:03:26 by jdepka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all : up

up : 
	@docker compose -f srcs/docker-compose.yml up -d

down : 
	@docker compose -f srcs/docker-compose.yml down

stop : 
	@docker compose -f srcs/docker-compose.yml stop

start : 
	@docker compose -f srcs/docker-compose.yml start

status : 
	@docker ps