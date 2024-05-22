/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:04:58 by jdepka            #+#    #+#             */
/*   Updated: 2024/05/22 16:48:15 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	gettime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_exit("Gettimeofday failed");
	return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
}

void	precise_usleep(long usec, t_table *table)
{
	long			start;
	long			elapsed;
	long			rem;

	start = gettime();
	while (gettime() - start < usec)
	{
		if (simulation_finished(table))
			break ;
		elapsed = gettime() - start;
		rem = usec - elapsed;
		if (rem > 1e4)
			usleep(rem / 2);
		else
		{
			while (gettime() - start < usec)
				;
		}
	}
}

void	clean(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = table->philos + i;
		pthread_mutex_destroy(&philo->philo_mutex);
		i++;
	}
	pthread_mutex_destroy(&table->table_mutex);
	pthread_mutex_destroy(&table->write_mutex);
	free(table->forks);
	free(table->philos);
}

void	error_exit(char *msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}
