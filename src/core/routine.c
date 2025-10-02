/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:21:56 by mandre            #+#    #+#             */
/*   Updated: 2025/10/02 15:46:14 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	think_routine(t_philo *philo)
{
	is_alive(philo);
	return (0);
}

static int	eat_routine(t_philo *philo)
{
	if (is_alive(philo))
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
	ft_usleep(philo->options.p_tte);
	set_time_count(philo);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	think_routine(philo);
	return (0);
}

static int	sleep_routine(t_philo *philo)
{
	is_alive(philo);
	write_action(philo, SLEEP);
	ft_usleep(philo->options.p_tts);
	//Calling think to inividually calculate 
	//thinking time
	return (0);
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
		ft_usleep(99999);
	}
	return (NULL);
}
