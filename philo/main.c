/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:00:09 by jdepka            #+#    #+#             */
/*   Updated: 2024/05/22 16:34:22 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		parse_args(&table, argv);
		data_init(&table);
		launch(&table);
		clean(&table);
	}
	else
	{
		error_exit("Wrong number of arguments!");
	}
	return (0);
}
