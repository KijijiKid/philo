/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:21:56 by mandre            #+#    #+#             */
/*   Updated: 2025/10/02 14:16:03 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_alive(t_philo *philo)
{
	size_t	last_meal;

	pthread_mutex_lock(&philo->meal_time_lock);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->meal_time_lock);
	if (get_curr_time() - last_meal)
		return (false);
	return (true);
}

static int	eat_routine(t_philo *philo)
{
	write_action(philo, EAT);
}

static int	sleep_routine(t_philo *philo)
{
	write_action(philo, SLEEP);
}

void	*routine(void *data)
{
	t_philo	*philo;
	bool	run;

	philo = (t_philo *)data;
	philo_hold(philo);
	while (1)
	{
		pthread_mutex_lock(philo->run_lock_ptr);
		run = *(philo->run_flag_ptr);
		pthread_mutex_unlock(philo->run_lock_ptr);
		if (!run)
			break ;
		eat_routine(philo);
		sleep_routine(philo);
	}
	write(1, "End\n", 4);
}
