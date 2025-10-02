/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:21:51 by mandre            #+#    #+#             */
/*   Updated: 2025/10/02 20:41:25 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	clean_meta_locks(t_meta *meta)
{
	if (pthread_mutex_destroy(&meta->sync_lock))
		return (throw_error(DSTRY_MUTEX_FAILED));
	if (pthread_mutex_destroy(&meta->write_lock))
		return (throw_error(DSTRY_MUTEX_FAILED));
	if (pthread_mutex_destroy(&meta->run_lock))
		return (throw_error(DSTRY_MUTEX_FAILED));
	return (0);
}

/// @brief Waits one second and than begins
/// cleaning up all resources 
void	clean_res(t_meta *meta)
{
	ft_usleep(1000);
	clean_total_forks(meta);
	clean_meta_locks(meta);
}
