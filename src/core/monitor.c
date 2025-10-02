/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:55:45 by mandre            #+#    #+#             */
/*   Updated: 2025/10/02 19:09:34 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_if_fed_up(t_meta *meta)
{
	unsigned int	i;
	unsigned int	meal_count;
	bool			all_ate_enough;

	if (meta->options.p_mec == 0)
		return (false);
	i = 0;
	all_ate_enough = true;
	while (i < meta->options.p_num)
	{
		pthread_mutex_lock(&meta->philo[i].meal_count_lock);
		meal_count = (meta->philo[i]).meal_count;
		pthread_mutex_unlock(&meta->philo[i].meal_count_lock);
		if ((meal_count < meta->options.p_mec))
		{
			all_ate_enough = false;
			break ;
		}
		i++;
	}
	return (all_ate_enough);
}

static bool	check_dead_flag(t_meta *meta)
{
	unsigned int	i;
	bool			alive;

	i = 0;
	while (i < meta->options.p_num)
	{
		pthread_mutex_lock(&meta->philo[i].alive_lock_ptr);
		alive = meta->philo[i].alive;
		pthread_mutex_unlock(&meta->philo[i].alive_lock_ptr);
		if (!alive)
		{
			pthread_mutex_lock(&meta->write_lock);
			printf("%ld %d died\n", get_curr_time() - meta->options.start_time,
				meta->philo[i].id);
			pthread_mutex_unlock(&meta->write_lock);
			return (true);
		}
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
		if (check_if_fed_up(meta))
			break ;
	}
	pthread_mutex_lock(&meta->run_lock);
	meta->run_flag = false;
	pthread_mutex_unlock(&meta->run_lock);
}
