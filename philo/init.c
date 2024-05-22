/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:21:10 by jdepka            #+#    #+#             */
/*   Updated: 2024/05/22 13:45:12 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo *philo, t_table *table, int i)
{
	int	philo_nbr;

	philo_nbr = table->philo_nbr;
	philo->first_fork = &table->forks[(i + 1) % philo_nbr];
	philo->second_fork = &table->forks[i];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &table->forks[i];
		philo->second_fork = &table->forks[(i + 1) % philo_nbr];
	}
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->meals_counter = 0;
		assign_forks(philo, table, i);
		philo->table = table;
		philo->full = 0;
		pthread_mutex_init(&philo->philo_mutex, NULL);
		i++;
	}
}

void	data_init(t_table *table)
{
	int	i;

	i = 0;
	table->end_simulation = 0;
	table->all_threads_ready = 0;
	table->threads_running_nbr = 0;
	pthread_mutex_init(&table->table_mutex, NULL);
	pthread_mutex_init(&table->write_mutex, NULL);
	table->philos = malloc(sizeof(t_philo) * table->philo_nbr);
	table->forks = malloc(sizeof(t_fork) * table->philo_nbr);
	if (!table->forks || !table->philos)
		error_exit("Error with malloc");
	while (i < table->philo_nbr)
	{
		pthread_mutex_init(&table->forks[i].fork, NULL);
		table->forks[i].id = i;
		i++;
	}
	philo_init(table);
}
