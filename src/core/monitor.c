/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:54:50 by mandre            #+#    #+#             */
/*   Updated: 2025/09/29 21:25:10 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief Sets the run_flag to false, whereupon
/// the philo routine loop breaks
static void	stop_routine(t_meta *meta)
{
	pthread_mutex_lock(&meta->run_lock);
	meta->run_flag = false;
	pthread_mutex_unlock(&meta->run_lock);
}

/// @brief Returns true if a philo died
static bool	check_if_dead(t_meta *meta)
{
	int i;

	i = 0;
	while (i < meta->options.p_num)
	{
		pthread_mutex_lock(&(meta->philo[i]).meal_time_lock);
		int a =  get_curr_time();
		if (meta->options.p_ttd <= ((meta->philo[i]).last_meal - a))
		{
			stop_routine(meta);
			write(1, "A\n", 2);
			return (true);
		}
		pthread_mutex_unlock(&(meta->philo[i]).meal_time_lock);
		i++;
	}
	return (false);
}

/// @brief Checks if all philos/threads ates enough
/// when yes it stops simulation
static bool	check_if_fed_up(t_meta *meta)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < meta->options.p_num)
	{
		pthread_mutex_lock(&(meta->philo[i]).meal_count_lock);
		if (meta->options.p_mec == (meta->philo[i]).total_meals)
			count += 1;
		pthread_mutex_unlock(&(meta->philo[i]).meal_count_lock);
		i++;
	}
	if (count == meta->options.p_num)
	{
		stop_routine(meta);
		//Here just passing random philo cause we won't use this just for write_lock(here)
		write_action(&meta->philo[0], P_ARE_FULL, 0);
		return (true);
	}
	return (false);
}

int	init_monitor(t_meta *meta)
{
	while (1)
	{
		sleep(1);
		if (check_if_fed_up(meta))
			break ;
		if (check_if_dead(meta))
			break ;
	}
	return (0);
}
