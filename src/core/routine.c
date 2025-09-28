/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:32:55 by mandre            #+#    #+#             */
/*   Updated: 2025/09/28 18:25:46 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_routine(t_philo *philo)
{
	
}

static void	sleep_routine(t_philo *philo)
{
	
}

void	*philo_routine(void *data)
{
	t_meta *meta;
	int 	i;
	int		p_id; // Philo Id -> Solution for passing meta instead of each philo struct

	meta = data;
	pthread_mutex_lock(&meta->curr_id_lock);
	p_id = meta->curr_id;
	pthread_mutex_unlock(&meta->curr_id_lock);
	philo_hold(meta);
	i = 1;
	while (i)
	{
		pthread_mutex_lock(&meta->run_lock);
		if (meta->run_flag == false)
			i = 0;
		pthread_mutex_unlock(&meta->run_lock);
		eat_routine(&(meta->philo[p_id]));
		sleep_routine(&(meta->philo[p_id]));
	}
}
