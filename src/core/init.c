/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:08:57 by mandre            #+#    #+#             */
/*   Updated: 2025/10/02 19:13:47 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_threads(t_meta *meta)
{
	unsigned int	i;

	i = 0;
	init_meta(meta);
	while (i < meta->options.p_num)
	{
		init_philo(meta, &meta->philo[i], i);
		if (pthread_create(&meta->philo[i].thread,
				NULL, &routine, &meta->philo[i]) != 0)
			throw_error(THREAD_CREATION_FAILED);
		if (pthread_detach(meta->philo[i].thread) != 0)
			throw_error(THREAD_CREATION_FAILED);
		i++;
	}
	philo_start(meta);
	return (0);
}
