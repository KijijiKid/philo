/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:17:41 by mandre            #+#    #+#             */
/*   Updated: 2025/09/26 18:46:38 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <sys/types.h>

int i = 0;

bool	check_if_dead(t_meta *philo_meta)
{
	// Check Logic TODO
	if (philo_meta->time_to_die == 100)
		printf("Hello Chiau\n");
}

bool	check_if_meals(t_meta *philo_meta)
{
	//Check Logic TODO
	
	pthread_mutex_lock(&philo_meta->monitor_thread);
	i++;
	pthread_mutex_unlock(&philo_meta->monitor_thread);
	if (i == 1000)
	{
		pthread_mutex_lock(&philo_meta->monitor_thread);
		philo_meta->run_philo = false;
		pthread_mutex_unlock(&philo_meta->monitor_thread);
	}
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
	while (philo_meta->run_philo)
	{
		if (check_if_dead(philo_meta))
			break ;
		if (check_if_meals(philo_meta))
			break ;
	}
	stop_philos(philo_meta);
}
