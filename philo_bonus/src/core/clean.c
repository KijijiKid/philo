/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:21:51 by mandre            #+#    #+#             */
/*   Updated: 2025/10/06 17:48:31 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	join_threads(t_meta	*meta)
{
	unsigned int	i;

	i = 0;
	while (i < meta->options.p_num)
	{
		if (pthread_join(meta->philo[i].thread, NULL) != 0)
			return (throw_error(THREAD_JOIN_FAILED));
		i++;
	}
	return (0);
}

/// @brief Waits one second and than begins
/// cleaning up all resources 
int	clean_res(t_meta *meta)
{
	join_threads(meta);
	if (sem_close(meta->forks) != 0)
			return (throw_error(SEM_CLOSE_FAILED));
	return (0);
}
