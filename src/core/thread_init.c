/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:42:10 by mandre            #+#    #+#             */
/*   Updated: 2025/09/24 20:07:44 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief This creates the philosopher struct with
/// initialised variables 
static void	philo_create(t_meta *philo_meta ,philo_t *philo , int id)
{
	philo->id = id;
	philo->number_of_meals = 0;
	philo->time_last_meal = 0;
	philo->dead = (bool *)philo_meta->dead;
}

int	create_threads(t_meta *philo_meta)
{
	int	i;

	if (pthread_create(&philo_meta->msg_thread, NULL, ((void *)monitor_init), NULL) != 0)
		perror("Creation Failed"); //Implement verbose -> TODO
	init_forks(philo_meta);
	i = 0;
	while (i < philo_meta->philosophers_count)
	{
		philo_create(philo_meta, &(philo_meta->philo)[i] ,i);
		if (pthread_create(&(philo_meta->philo)[i].thread, NULL, ((void *)routine), &(philo_meta->philo)[i]) != 0)
			perror("Creation Failed"); //Implement verbose -> TODO
		assign_forks(philo_meta, &(philo_meta->philo)[i]);
		i++;
	}
	return (0);

}
