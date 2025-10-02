/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:55:45 by mandre            #+#    #+#             */
/*   Updated: 2025/10/02 16:17:06 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_dead_flag(t_meta *meta)
{
	unsigned int	i;
	bool			alive;

	i = 0;
	while (i < meta->options.p_num)
	{
		pthread_mutex_lock(&meta->philo[i].alive_lock_ptr);
		alive = (meta->philo[i]).alive;
		pthread_mutex_unlock(&meta->philo[i].alive_lock_ptr);
		if (!alive)
			return (true);		
		i++;
	}
	return (false);
}

void	init_monitor(t_meta *meta)
{
	while (1)
	{
		if (check_dead_flag(meta))
			break ;
	}
	pthread_mutex_lock(&meta->run_lock);
	meta->run_flag =  false;
	pthread_mutex_unlock(&meta->run_lock);
}
