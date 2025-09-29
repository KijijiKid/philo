/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:10:48 by mandre            #+#    #+#             */
/*   Updated: 2025/09/29 14:57:00 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief After all threads are created this
/// function called by the main thread sets the 
/// wait flag to false so the philos can begin their
/// routine
void	philo_start(t_meta *meta)
{
	pthread_mutex_lock(&meta->wait_lock);
	meta->wait_flag = false;
	pthread_mutex_unlock(&meta->wait_lock);
}

/// @brief Holds each thread/philo in a while loop
/// as long as the others are not created (wait_flag == true)
void	philo_hold(t_philo *philo)
{
	int i;

	i = 1;
	while (i)
	{
		pthread_mutex_lock(&philo->wait_lock);
		if (*philo->wait_flag == false)
			i = 0;
		pthread_mutex_unlock(&philo->wait_lock);
	}
}
