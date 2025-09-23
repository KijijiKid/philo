/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:42:10 by mandre            #+#    #+#             */
/*   Updated: 2025/09/23 20:27:28 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief This creates the philosopher struct with
/// initialised variables 
void	philo_create(philo_t *philo, int id)
{
	philo->id = id;
	philo->number_of_meals = 0;
	philo->time_last_meal = 0;
}

int	create_threads(t_meta *philo_meta)
{
	int	i;

	// pthread_mutex_init(&mutex, NULL);
	i = 0;
	while (i < philo_meta->philosophers_count)
	{
		philo_create(&(philo_meta->philo)[i] ,i);
		if (pthread_create(&(philo_meta->philo)[i].thread, NULL, ((void *)routine), &(philo_meta->philo)[i]) != 0)
			perror("Creation Failed"); //Implement verbose -> TODO
		i++;
	}
	return (0);
}
