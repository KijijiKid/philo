/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:54:50 by mandre            #+#    #+#             */
/*   Updated: 2025/09/28 16:34:26 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_if_dead(t_meta *meta)
{

}

static void	check_if_fed_up(t_meta *meta)
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
		//Checks conditions
	}
	stop_routine(meta);
}
