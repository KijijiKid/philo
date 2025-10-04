/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:48:36 by mandre            #+#    #+#             */
/*   Updated: 2025/10/04 19:26:35 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief Destroys the forks/mutexes in the
/// total forks array
int	clean_total_forks(t_meta *meta)
{
	unsigned int	i;

	i = 0;
	while (i < meta->options.p_num)
	{
		// if (pthread_mutex_destroy(&meta->total_forks[i]) != 0)
		// 	return (throw_error(DSTRY_MUTEX_FAILED));
		if (sem_close(&meta->philo[i].meal_count_lock) != 0)
			return (throw_error(SEM_CLOSE_FAILED));
		if (sem_close(&meta->philo[i].meal_time_lock) != 0)
			return (throw_error(SEM_CLOSE_FAILED));
		if (sem_close(&meta->philo[i].alive_lock) != 0)
			return (throw_error(SEM_CLOSE_FAILED));
		i++;
	}
	return (0);
}

/// @brief Creates the total forks/mutex array 
/// in the amount philo's need them
/// Assigning to l/r happens later
int	create_total_forks(t_meta *meta)
{
	unsigned int	i;

	i = 0;
	while (i < meta->options.p_num)
	{
		if (pthread_mutex_init(&meta->total_forks[i], NULL) != 0)
			return (throw_error(INIT_MUTEX_FAILED));
		i++;
	}
	return (0);
}
