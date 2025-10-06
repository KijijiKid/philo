/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:55:45 by mandre            #+#    #+#             */
/*   Updated: 2025/10/06 18:05:46 by mandre           ###   ########.fr       */
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
		alive = meta->philo[i].alive;
		if (!alive)
		{
			meta->run_flag = false;
			meta->write_flag = true;
			printf("%ld %d died\n", get_curr_time()
				- meta->start_time, meta->philo[i].id + 1);
			return (true);
		}
		i++;
	}
	return (false);
}

int	init_monitor(t_meta *meta)
{
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
