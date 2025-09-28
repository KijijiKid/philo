/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:32:55 by mandre            #+#    #+#             */
/*   Updated: 2025/09/28 19:36:32 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat_routine(t_philo *philo)
{
	printf("%d", philo->id);
	return (1);
}

static int	sleep_routine(t_philo *philo)
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
		write(1, "A\n", 2);
		if (eat_routine(&(meta->philo[p_id])))
			break ;
		// sleep_routine(&(meta->philo[p_id]));
	}
}
