/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:54:50 by mandre            #+#    #+#             */
/*   Updated: 2025/09/30 17:54:48 by mandre           ###   ########.fr       */
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
	unsigned int	i;

	i = 0;
	while (i < meta->options.p_num)
	{
		pthread_mutex_lock(&(meta->philo[i]).alive_flag_lock);
		if ((meta->philo)[i].philo_alive == false)
		{
			stop_routine(meta);
			printf("%ld %d is dead\n", get_curr_time() - meta->philo[i].options.start_time, meta->philo[i].id);
			return (true);
		}
		pthread_mutex_unlock(&(meta->philo[i]).alive_flag_lock);
		i++;
	}
	return (false);
}

/// @brief Checks if all philos/threads ates enough
/// when yes it stops simulation
static bool	check_if_fed_up(t_meta *meta)
{
	unsigned int i;
	bool	all_ate_enough;

	// Diable eating terminator argc[5] isn't provieded
	if (meta->options.p_mec == 0)
		return (false);
	i = 0;
	all_ate_enough = true;
	while (i < meta->options.p_num && all_ate_enough)
	{
		pthread_mutex_lock(&(meta->philo[i]).meal_count_lock);
		if ((meta->philo[i]).total_meals < meta->options.p_mec)
			all_ate_enough = false;
		pthread_mutex_unlock(&(meta->philo[i]).meal_count_lock);
		i++;
	}
	if (all_ate_enough)
	{
		write_action(&meta->philo[0], P_ARE_FULL, 0);
		stop_routine(meta);
	}
	return (all_ate_enough);
}

int	init_monitor(t_meta *meta)
{
	while (1)
	{
		if (check_if_fed_up(meta))
			break ;
		if (check_if_dead(meta))
			break ;
	}
	return (0);
}
