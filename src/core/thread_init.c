/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:42:10 by mandre            #+#    #+#             */
/*   Updated: 2025/09/24 12:27:51 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief This creates the philosopher struct with
/// initialised variables 
static void	philo_create(t_meta *philo_meta, philo_t *philo, int id)
{
	philo->id = id;
	philo->number_of_meals = 0;
	philo->time_last_meal = 0;
	philo->time_to_die = philo_meta->time_to_die;
	philo->time_to_eat = philo_meta->time_to_eat;
	philo->time_to_sleep = philo_meta->time_to_sleep;
}

int	create_threads(t_meta *philo_meta)
{
	int	i;

	i = 0;
	init_forks(philo_meta);
	//Init MSG thread
	// if (pthread_create(&philo_meta->msg_thread, NULL, ((void *)monitor_thread), NULL) != 0)
	// 	perror("Creation MSG Thread");
	while (i < philo_meta->philosophers_count)
	{
		philo_create(philo_meta, &(philo_meta->philo)[i] ,i);
		if (pthread_create(&(philo_meta->philo)[i].thread, NULL, ((void *)routine), &(philo_meta->philo)[i]) != 0)
			perror("Creation Failed"); //Implement verbose -> TODO
		// assign_forks(philo_meta, &(philo_meta->philo)[i]);
		i++;
	}
	return (0);
}
