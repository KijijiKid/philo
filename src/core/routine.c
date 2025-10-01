/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:32:55 by mandre            #+#    #+#             */
/*   Updated: 2025/10/01 13:56:52 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool cal_if_dead(t_philo *philo)
{
    size_t last;
    size_t now;

    pthread_mutex_lock(&philo->meal_time_lock);
    last = philo->last_meal;
    pthread_mutex_unlock(&philo->meal_time_lock);

    now = get_curr_time();
    if (now - last > philo->options.p_ttd) {
        pthread_mutex_lock(&philo->alive_flag_lock);
        philo->philo_alive = false;
        pthread_mutex_unlock(&philo->alive_flag_lock);
        return true;
    }
    return false;
}

static int	sleep_routine(t_philo *philo)
{
	write_action(philo , SLEEP, philo->id);
	ft_usleep(philo->options.p_tts);
	return (0);
}

static int	eat_routine(t_philo *philo)
{
	if (cal_if_dead(philo))
		return (1);
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->forks[1]);
		pthread_mutex_lock(&philo->forks[0]);
	}
	else
	{
		pthread_mutex_lock(&philo->forks[0]);
		pthread_mutex_lock(&philo->forks[1]);
	}
	write_action(philo, T_FORK, philo->id);
	write_action(philo, T_FORK, philo->id);
	write_action(philo, EAT, philo->id);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = get_curr_time();
	pthread_mutex_unlock(&philo->meal_time_lock);
	ft_usleep(philo->options.p_tte);
	pthread_mutex_lock(&philo->meal_count_lock);
	philo->total_meals += 1;
	pthread_mutex_unlock(&philo->meal_count_lock);
	if (philo->id % 2)
	{
		pthread_mutex_unlock(&philo->forks[0]);
		pthread_mutex_unlock(&philo->forks[1]);
	}
	else
	{
		pthread_mutex_unlock(&philo->forks[1]);
		pthread_mutex_unlock(&philo->forks[0]);
	}
	sleep_routine(philo);
	return (0);
}

static int	think_routine(t_philo *philo)
{
	long	time_to_think;

	if (cal_if_dead(philo))
		return (1);
	pthread_mutex_lock(&philo->meal_time_lock);
	time_to_think = (philo->options.p_ttd - (get_curr_time() - philo->last_meal));
	pthread_mutex_unlock(&philo->meal_time_lock);
	write_action(philo, THINK, philo->id);
	return (0);
}

void	*philo_routine(void *data)
{
	t_philo *philo;
	bool	run_flag;

	philo = data;
	philo_hold(philo);
	if (philo->id / 2)
		think_routine(philo);
	while (1)
	{
		pthread_mutex_lock(&philo->run_lock);
		run_flag = philo->run_flag;
		pthread_mutex_unlock(&philo->run_lock);
		if (!run_flag)
			return (NULL);
		if (eat_routine(philo) == 1)
			return (NULL);
		if (sleep_routine(philo) == 1)
			return (NULL);
	}
	return (NULL);
}
