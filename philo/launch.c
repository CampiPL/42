/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:45:01 by jdepka            #+#    #+#             */
/*   Updated: 2024/05/23 16:03:14 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	write_status('t', philo);
	if (philo->table->philo_nbr % 2 == 0)
		return ;
	t_eat = philo->table->time_to_eat;
	t_sleep = philo->table->time_to_sleep;
	t_think = t_eat * 2 - t_sleep;
	if (t_think < 0)
		t_think = 0;
	precise_usleep(t_think * 0.42, philo->table);
}

static void	*lone_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal, gettime());
	increase_long(&philo->table->table_mutex,
		&philo->table->threads_running_nbr);
	write_status('f', philo);
	while (!simulation_finished(philo->table))
		usleep(200);
	return (NULL);
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	write_status('f', philo);
	pthread_mutex_lock(&philo->second_fork->fork);
	write_status('f', philo);
	write_status('e', philo);
	precise_usleep(philo->table->time_to_eat, philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal, gettime());
	philo->meals_counter++;
	if (philo->table->nbr_limit_meals > 0
		&& philo->meals_counter == philo->table->nbr_limit_meals)
		set_int(&philo->philo_mutex, &philo->full, 1);
	pthread_mutex_unlock(&philo->first_fork->fork);
	pthread_mutex_unlock(&philo->second_fork->fork);
}

static void	*lunch_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal, gettime());
	increase_long(&philo->table->table_mutex,
		&philo->table->threads_running_nbr);
	desynchronize_philos(philo);
	while (!simulation_finished(philo->table))
	{
		if (philo->full)
			break ;
		eat(philo);
		write_status('s', philo);
		precise_usleep(philo->table->time_to_sleep, philo->table);
		thinking(philo);
	}
	return (NULL);
}

void	launch(t_table *table)
{
	int	i;

	i = 0;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->philo_nbr == 1)
		pthread_create(&table->philos[0].thread_id, NULL,
			lone_philo, &table->philos[0]);
	else
	{
		while (i < table->philo_nbr)
		{
			pthread_create(&table->philos[i].thread_id, NULL,
				lunch_simulation, &table->philos[i]);
			i++;
		}
	}
	pthread_create(&table->monitor, NULL, monitor_launch, table);
	table->start_simulation = gettime();
	set_int(&table->table_mutex, &table->all_threads_ready, 1);
	i = 0;
	while (i < table->philo_nbr)
		pthread_join(table->philos[i++].thread_id, NULL);
	set_int(&table->table_mutex, &table->end_simulation, 1);
	pthread_join(table->monitor, NULL);
}
