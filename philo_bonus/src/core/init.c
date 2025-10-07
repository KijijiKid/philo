/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:08:57 by mandre            #+#    #+#             */
/*   Updated: 2025/10/07 17:27:42 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		i++;
	}
	meta->start_time = get_curr_time();
	philo_start(meta);
	return (0);
}
