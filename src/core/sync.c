/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:09:24 by mandre            #+#    #+#             */
/*   Updated: 2025/10/02 17:52:35 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief After all threads are created this
/// function called by the main thread sets the 
/// sync flag to true so the philos can begin their
/// routine
void	philo_start(t_meta *meta)
{
	pthread_mutex_lock(&meta->sync_lock);
	meta->sync_flag = true;
	pthread_mutex_unlock(&meta->sync_lock);
}

/// @brief Holds each thread/philo in a while loop
/// as long as the others are not created (start == false)
/// This resolves in a more or less sync of all threads
/// ft_usleep(1000) => Avoid to burn 100% of the CPU so 1ms
/// wait after each loop cycle
void	philo_hold(t_philo *philo)
{
	bool	start;

	while (1)
	{
		pthread_mutex_lock(philo->sync_lock_ptr);
		start = *(philo->sync_flag_ptr);
		pthread_mutex_unlock(philo->sync_lock_ptr);
		if (start)
			break ;
		ft_usleep(1000);
	}
}