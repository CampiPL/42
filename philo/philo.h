/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:45:57 by jdepka            #+#    #+#             */
/*   Updated: 2024/05/23 15:18:26 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_table	t_table;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_philo
{
	int				id;
	long			meals_counter;
	int				full;
	long			last_meal;
	t_fork			*first_fork;
	t_fork			*second_fork;
	pthread_t		thread_id;
	pthread_mutex_t	philo_mutex;
	t_table			*table;
}	t_philo;

struct	s_table
{
	long			philo_nbr;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_limit_meals;
	long			start_simulation;
	int				end_simulation;
	int				all_threads_ready;
	long			threads_running_nbr;
	pthread_t		monitor;
	pthread_mutex_t	table_mutex;
	pthread_mutex_t	write_mutex;
	t_fork			*forks;
	t_philo			*philos;
};

void	error_exit(char *msg);
void	parse_args(t_table *table, char *argv[]);
void	data_init(t_table *table);
void	launch(t_table *table);
void	set_int(pthread_mutex_t *mutex, int *dest, int value);
int		get_int(pthread_mutex_t *mutex, int *src);
void	set_long(pthread_mutex_t *mutex, long *dest, long value);
long	get_long(pthread_mutex_t *mutex, long *src);
int		simulation_finished(t_table *table);
void	wait_all_threads(t_table *table);
long	gettime(void);
void	precise_usleep(long usec, t_table *table);
void	write_status(char status, t_philo *philo);
void	*monitor_launch(void *data);
int		all_threads_running(pthread_mutex_t *mutex,
			long *threads, long philo_nbr);
void	increase_long(pthread_mutex_t *mutex, long *value);
void	clean(t_table *table);
void	desynchronize_philos(t_philo *philo);
void	thinking(t_philo *philo);

#endif