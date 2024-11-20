# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 20:57:06 by jdepka            #+#    #+#              #
#    Updated: 2024/11/20 13:06:31 by jdepka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all : up

up : 
	mkdir -p /home/jdepka/data/mariadb
	mkdir -p /home/jdepka/data/wordpress
	@docker compose -f srcs/docker-compose.yml up -d

down :
	@docker compose -f srcs/docker-compose.yml down
	sudo chown -R jdepka:jdepka /home/jdepka/data/mariadb
	sudo chown -R jdepka:jdepka /home/jdepka/data/wordpress
	rm -rf /home/jdepka/data/mariadb
	rm -rf /home/jdepka/data/wordpress
	docker volume rm mariadb wordpress

stop : 
	@docker compose -f srcs/docker-compose.yml stop

start : 
	@docker compose -f srcs/docker-compose.yml start

status : 
	@docker ps