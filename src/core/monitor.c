/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:54:50 by mandre            #+#    #+#             */
/*   Updated: 2025/09/28 18:02:32 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_if_dead(t_meta *meta)
{
	int i;

	i = 0;
	while (i < meta->options.p_num)
	{
		pthread_mutex_lock(&(meta->philo[i]).meal_time_lock);
		if (meta->options.p_ttd <= (get_curr_time() - (meta->philo[i]).last_meal))
			return (true);
		pthread_mutex_lock(&(meta->philo[i]).meal_time_lock);
	}
	return (false)
}

static bool	check_if_fed_up(t_meta *meta)
{
	
}

/// @brief Sets the run_flag to false, whereupon
/// the philo routine loop breaks
static void	stop_routine(t_meta *meta)
{
	pthread_mutex_lock(&meta->run_lock);
	meta->run_flag = false;
	pthread_mutex_lock(&meta->run_lock);
}

void	init_monitor(t_meta *meta)
{
	while (1)
	{
		check_if_fed_up(meta);
		check_if_dead(meta);
	}
	stop_routine(meta);
}
