/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:08:57 by mandre            #+#    #+#             */
/*   Updated: 2025/10/01 16:47:11 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	init_forks(t_meta *meta)
{
	int	i;

	i = 0;
	meta->sync_flag = false;
	pthread_mutex_init(&meta->sync_lock, NULL);
	while (i < meta->options.p_num)
	{
		meta->philo[i].sync_lock_ptr = &meta->sync_lock;
		meta->philo[i].sync_flag_ptr = &meta->sync_flag;
		if (pthread_create(&meta->philo[i].thread, NULL, &routine, NULL) != 0)
			throw_error(THREAD_CREATION_FAILED);
		i++;
	}
	philo_start(meta);
}
