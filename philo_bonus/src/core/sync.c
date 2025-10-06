/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:09:24 by mandre            #+#    #+#             */
/*   Updated: 2025/10/06 16:13:26 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief After all threads are created this
/// function called by the main thread sets the 
/// sync flag to true so the philos can begin their
/// routine
void	philo_start(t_meta *meta)
{
	sem_wait(meta->sync_lock);
	meta->sync_flag = true;
	sem_post(meta->sync_lock);
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
		sem_wait(philo->sync_lock);
		start = *(philo->sync_flag_ptr);
		sem_post(philo->sync_lock);
		if (start)
			break ;
	}
}
