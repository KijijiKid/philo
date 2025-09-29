/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:32:55 by mandre            #+#    #+#             */
/*   Updated: 2025/09/29 18:41:59 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[0]);
	write_action(philo, T_FORK, philo->id, true);
	pthread_mutex_lock(&philo->forks[1]);
	write_action(philo, T_FORK, philo->id, true);
	write_action(philo, EAT, philo->id, true);
	ft_usleep(philo->options.p_tte);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = get_curr_time();	
	pthread_mutex_unlock(&philo->meal_time_lock);
	pthread_mutex_lock(&philo->meal_count_lock);
	philo->total_meals += 1;
	pthread_mutex_unlock(&philo->meal_count_lock);
	pthread_mutex_unlock(&philo->forks[0]);
	pthread_mutex_unlock(&philo->forks[1]);
	return (0);
}

static int	sleep_routine(t_philo *philo)
{
	write_action(philo , SLEEP, philo->id, true);
	ft_usleep(philo->options.p_tts * 1000);
	return (0);
}

void	*philo_routine(void *data)
{
	t_philo *philo;
	int 	i;

	philo = data;
	philo_hold(philo);
	if (philo->id % 2)
		sleep_routine(philo);
	i = 1;
	while (i)
	{
		pthread_mutex_lock(&philo->run_lock);
		if (*philo->run_flag == false)
			i = 0;
		pthread_mutex_unlock(&philo->run_lock);
		if (i == 1)
		{
			eat_routine(philo);
			sleep_routine(philo);
		}
	}
}
