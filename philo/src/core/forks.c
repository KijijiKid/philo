/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:48:36 by mandre            #+#    #+#             */
/*   Updated: 2025/10/08 16:22:11 by mandre           ###   ########.fr       */
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
		if (pthread_mutex_destroy(&meta->total_forks[i]) != 0)
			return (throw_error(DSTRY_MUTEX_FAILED));
		if (pthread_mutex_destroy(&meta->philo[i].meal_count_lock) != 0)
			return (throw_error(DSTRY_MUTEX_FAILED));
		if (pthread_mutex_destroy(&meta->philo[i].meal_time_lock) != 0)
			return (throw_error(DSTRY_MUTEX_FAILED));
		if (pthread_mutex_destroy(&meta->philo[i].alive_lock) != 0)
			return (throw_error(DSTRY_MUTEX_FAILED));
		i++;
	}
	return (0);
}

void	assign_forks(t_meta *meta, t_philo *philo)
{
	philo->r_fork = &meta->total_forks[philo->id];
	if (philo->id == 0)
		philo->l_fork = &meta->total_forks[philo->options.p_num - 1];
	else
		philo->l_fork = &meta->total_forks[philo->id - 1];
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
