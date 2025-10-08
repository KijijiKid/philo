/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:21:56 by mandre            #+#    #+#             */
/*   Updated: 2025/10/08 16:03:50 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	sleep_routine(t_philo *philo, bool write)
{
	if (!is_alive(philo))
		return (1);
	write_action(philo, SLEEP, write);
	ft_usleep(philo->options.p_tts);
	return (0);
}

static int	think_routine(t_philo *philo, bool write)
{
	long	time_to_think;
	long	last_meal;
	bool	write_flag;

	if (!is_alive(philo))
		return (1);
	write_flag = write;
	pthread_mutex_lock(&philo->meal_time_lock);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->meal_time_lock);
	time_to_think = (philo->options.p_ttd
			- (get_curr_time() - last_meal)
			- philo->options.p_tte) / 2;
	if (time_to_think < 0)
		return (0);
	if (time_to_think == 0)
		return (0);
	if (time_to_think > 600)
		time_to_think = 200;
	write_action(philo, THINK, write_flag);
	ft_usleep(time_to_think);
	return (0);
}

static int	eat_routine(t_philo *philo, bool write)
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
	write_action(philo, T_FORK, write);
	write_action(philo, T_FORK, write);
	write_action(philo, EAT, write);
	set_time_count(philo);
	ft_usleep(philo->options.p_tte);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	sleep_routine(philo, write);
	return (0);
}

static int	lone_philo(t_philo *philo)
{
	if (philo->options.p_num == 1)
	{
		printf("%ld %d philo died\n", *philo->options.start_time
			- get_curr_time(), philo->id + 1);
		return (1);
	}
	return (0);
}

void	*routine(void *data)
{
	t_philo	*philo;
	bool	run;
	bool	write;

	philo = (t_philo *)data;
	if (lone_philo(philo))
		return (NULL);
	philo_hold(philo);
	set_first_meal_time(philo);
	if (philo->id % 2)
		sleep_routine(philo, false);
	write = true;
	while (1)
	{
		pthread_mutex_lock(philo->run_lock_ptr);
		run = *(philo->run_flag_ptr);
		pthread_mutex_unlock(philo->run_lock_ptr);
		if (!run || !philo->alive)
			break ;
		if (eat_routine(philo, true))
			write = false;
		think_routine(philo, write);
	}
	return (NULL);
}
