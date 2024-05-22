/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:49:23 by jdepka            #+#    #+#             */
/*   Updated: 2024/05/22 16:47:29 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(char status, t_philo *philo)
{
	long	elapsed;

	elapsed = gettime() - philo->table->start_simulation;
	if (philo->full)
		return ;
	pthread_mutex_lock(&philo->table->write_mutex);
	if (status == 'f' && !simulation_finished(philo->table))
		printf("%-6ld %d has taken a fork\n", elapsed, philo->id);
	else if (status == 'e' && !simulation_finished(philo->table))
		printf("%-6ld %d is eating\n", elapsed, philo->id);
	else if (status == 's' && !simulation_finished(philo->table))
		printf("%-6ld %d is sleeping\n", elapsed, philo->id);
	else if (status == 't' && !simulation_finished(philo->table))
		printf("%-6ld %d is thinking\n", elapsed, philo->id);
	else if (status == 'd')
		printf("%-6ld %d died\n", elapsed, philo->id);
	pthread_mutex_unlock(&philo->table->write_mutex);
}
