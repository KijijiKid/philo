/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:21:56 by mandre            #+#    #+#             */
/*   Updated: 2025/10/02 17:13:53 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	think_routine(t_philo *philo)
{
	long	time_to_think;

	if (!is_alive(philo))
		return (1);
	pthread_mutex_lock(&philo->meal_time_lock);
	time_to_think = (philo->options.p_ttd - (get_curr_time() - philo->last_meal)) / 2;
	pthread_mutex_unlock(&philo->meal_time_lock);
	write_action(philo, THINK);
	ft_usleep(time_to_think * 1000);
	return (0);
}


static int	eat_routine(t_philo *philo)
{
	if (!is_alive(philo))
		return (1);
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
	}
	write_action(philo, T_FORK);
	write_action(philo, T_FORK);
	write_action(philo, EAT);
	set_time_count(philo);
	usleep(philo->options.p_tte * 100);
	if (philo->id % 2)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	return (think_routine(philo));
}

static int	sleep_routine(t_philo *philo)
{
	if (!is_alive(philo))
		return (1);
	write_action(philo, SLEEP);
	ft_usleep(philo->options.p_tts * 1000);
	return (think_routine(philo));
}

void	*routine(void *data)
{
	t_philo	*philo;
	bool	run;

	philo = (t_philo *)data;
	philo_hold(philo);
	set_first_meal_time(philo);
	while (1)
	{
		pthread_mutex_lock(philo->run_lock_ptr);
		run = *(philo->run_flag_ptr);
		pthread_mutex_unlock(philo->run_lock_ptr);
		if (!run || !philo->alive)
			break ;
		if (eat_routine(philo))
			break ;
		if (sleep_routine(philo))
			break ;
	}
	return (NULL);
}
