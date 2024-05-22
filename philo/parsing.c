/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:08:28 by jdepka            #+#    #+#             */
/*   Updated: 2024/05/17 17:43:02 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_atol(const char *str)
{
	long	num;

	num = 0;
	while (*str)
		num = num * 10 + (*str++ - '0');
	if (num > INT_MAX)
		error_exit("Argument too big, INT_MAX is the limit!");
	return (num);
}

static int	is_nbr(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

void	parse_args(t_table *table, char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_nbr(argv[i]))
			error_exit("Arguments are of a wrong type!");
		i++;
	}
	table->philo_nbr = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		table->nbr_limit_meals = ft_atol(argv[5]);
	else
		table->nbr_limit_meals = -1;
}
