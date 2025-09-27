/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:17:41 by mandre            #+#    #+#             */
/*   Updated: 2025/09/27 13:29:08 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <sys/types.h>

int i = 0;

bool	check_if_dead(t_meta *philo_meta)
{
	int		i;
	size_t	curr_time_span;

	i = 0;
	while (i < philo_meta->philosophers_count)
	{
		pthread_mutex_lock(&philo_meta->dead_lock);
		curr_time_span = get_curr_time() - (philo_meta->philo[i].last_meal);
		pthread_mutex_unlock(&philo_meta->dead_lock);
		if (curr_time_span >= philo_meta->time_to_die)
		{
			pthread_mutex_lock(&philo_meta->monitor_thread);
			printf("Philo is Dead\n");
			pthread_mutex_unlock(&philo_meta->monitor_thread);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	check_if_meals(t_meta *philo_meta)
{
	//Check Logic TODO
	int i;

	i = 0;
	while (i < philo_meta->philosophers_count)
	{
		if ((philo_meta->philo)[i].number_of_meals == philo_meta->number_of_times_each_philosopher_must_eat)
		{
			pthread_mutex_lock(&philo_meta->monitor_thread);
			printf("Philos ate enough");
			pthread_mutex_unlock(&philo_meta->monitor_thread);
			return (true);
		}
		i++;
	}
	return (false);
}

void	stop_philos(t_meta *philo_meta)
{
	pthread_mutex_lock(&philo_meta->monitor_thread);
	philo_meta->run_philo = false;
	pthread_mutex_unlock(&philo_meta->monitor_thread);
}

/// @brief The monitor init initializes a endless while loop
/// that checks	if a philiosopher is dead -> if so the flag 
/// for philo is dead turns true. The other case is when 
/// all of the philosophers ate enough
/// ! This function runs on the main thread !
void	monitor_init(t_meta *philo_meta)
{
	while (1)
	{
		if (check_if_dead(philo_meta) || check_if_meals(philo_meta))
			break ;
	}
	stop_philos(philo_meta);
}
