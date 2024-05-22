/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:05:58 by jdepka            #+#    #+#             */
/*   Updated: 2024/05/17 14:13:14 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_int(pthread_mutex_t *mutex, int *dest, int value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

int	get_int(pthread_mutex_t *mutex, int *src)
{
	int	res;

	pthread_mutex_lock(mutex);
	res = *src;
	pthread_mutex_unlock(mutex);
	return (res);
}

void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

long	get_long(pthread_mutex_t *mutex, long *src)
{
	long	res;

	pthread_mutex_lock(mutex);
	res = *src;
	pthread_mutex_unlock(mutex);
	return (res);
}

int	simulation_finished(t_table *table)
{
	return (get_int(&table->table_mutex, &table->end_simulation));
}
