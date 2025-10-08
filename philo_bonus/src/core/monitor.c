/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:55:45 by mandre            #+#    #+#             */
/*   Updated: 2025/10/08 16:59:59 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		meal_count = (meta->philo[i]).meal_count;
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
		if (!is_alive(&(meta->philo[i])))
		{
			pthread_mutex_lock(&meta->run_lock);
			meta->run_flag = false;
			pthread_mutex_unlock(&meta->run_lock);
			pthread_mutex_lock(&meta->write_lock);
			printf("%ld %d died\n", get_curr_time()
				- meta->start_time, meta->philo[i].id + 1);
			pthread_mutex_unlock(&meta->write_lock);
			return (true);
		}
		i++;
	}
	return (false);
}

int	init_monitor(t_meta *meta)
{
	if (meta->options.p_num == 1)
	{
		ft_usleep(10);
		return (0);
	}
	while (1)
	{
		if (check_dead_flag(meta))
			break ;
		if (check_if_fed_up(meta))
			break ;
	}
	meta->run_flag = false;
	return (0);
}
