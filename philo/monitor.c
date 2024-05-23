/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:53:11 by jdepka            #+#    #+#             */
/*   Updated: 2024/05/23 15:36:51 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_died(t_philo *philo)
{
	long	elapsed;
	long	time_to_die;

	if (get_int(&philo->philo_mutex, &philo->full))
		return (0);
	elapsed = gettime() - get_long(&philo->philo_mutex,
			&philo->last_meal);
	time_to_die = philo->table->time_to_die;
	if (elapsed > time_to_die)
		return (1);
	return (0);
}

void	*monitor_launch(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *) data;
	while (!all_threads_running(&table->table_mutex,
			&table->threads_running_nbr, table->philo_nbr))
			;
	while (!simulation_finished(table))
	{
		i = 0;
		while (i < table->philo_nbr && !simulation_finished(table))
		{
			if (philo_died(table->philos + i))
			{
				set_int(&table->table_mutex, &table->end_simulation, 1);
				write_status('d', table->philos + i);
			}
			i++;
		}
	}
	return (NULL);
}
