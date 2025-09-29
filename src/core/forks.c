/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:36:49 by mandre            #+#    #+#             */
/*   Updated: 2025/09/29 17:59:52 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief Destroys/deinitializes the forks/mutexes
int	destory_forks(t_meta *meta)
{
	int i;

	i = 0;
	while (i < meta->options.p_num)
	{
		if (pthread_mutex_destroy(&meta->total_forks[i]) != 0)
			return (throw_error(DSTRY_MUTEX_FAILED));
		i++;
	}
	return (0);
}

/// @brief Assign each philo/thread a fork pair
/// [0] = l_fork, [1] = r_fork
void	assign_forks(t_meta *meta)
{
	int	i;

	i = 0;
	while (i < meta->options.p_num)
	{
		if (meta->philo[i].id == 1)
			meta->philo[i].forks[0] = meta->total_forks[(meta->options.p_num - 1)];
		else
			meta->philo[i].forks[0] = meta->total_forks[(meta->philo[i].id - 2)];
		meta->philo[i].forks[1] = meta->total_forks[(meta->philo[i].id - 1)];
		i++;
	}
}

/// @brief Initalizes as many forks/mutexes
/// as provided via argv[1]
int	init_forks(t_meta *meta)
{
	int i;

	i = 0;
	while (i < meta->options.p_num)
	{
		if (pthread_mutex_init(&meta->total_forks[i], NULL) != 0)
			return (throw_error(INIT_MUTEX_FAILED));
		i++;
	}
	return (0);
}
