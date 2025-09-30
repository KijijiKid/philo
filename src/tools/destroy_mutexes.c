/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:27:58 by mandre            #+#    #+#             */
/*   Updated: 2025/09/30 11:40:47 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_specified_mtx(t_meta *meta)
{
	unsigned int	i;

	i = 0;
	while (i < meta->options.p_num)
	{
		if (pthread_mutex_destroy(&(meta->philo[i]).meal_time_lock) != 0)
			return(throw_error(DSTRY_MUTEX_FAILED));
		i++;
	}
	return (0);
}

int	destroy_mutexes(t_meta *meta)
{
	if (pthread_mutex_destroy(&meta->wait_lock) != 0)
		return(throw_error(DSTRY_MUTEX_FAILED));
	if (pthread_mutex_destroy(&meta->write_lock) != 0)
		return(throw_error(DSTRY_MUTEX_FAILED));
	if (pthread_mutex_destroy(&meta->run_lock) != 0)
		return(throw_error(DSTRY_MUTEX_FAILED));
	philo_specified_mtx(meta);
	destory_forks(meta);
	return (0);
}