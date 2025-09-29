/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:32:55 by mandre            #+#    #+#             */
/*   Updated: 2025/09/29 20:47:31 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	sleep_routine(t_philo *philo)
{
	write_action(philo , SLEEP, philo->id);
	ft_usleep(philo->options.p_tts);
	return (0);
}

static int	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[0]);
	write_action(philo, T_FORK, philo->id);
	pthread_mutex_lock(&philo->forks[1]);
	write_action(philo, T_FORK, philo->id);
	write_action(philo, EAT, philo->id);
	ft_usleep(philo->options.p_tte);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = get_curr_time();	
	pthread_mutex_unlock(&philo->meal_time_lock);
	pthread_mutex_lock(&philo->meal_count_lock);
	philo->total_meals += 1;
	pthread_mutex_unlock(&philo->meal_count_lock);
	pthread_mutex_unlock(&philo->forks[0]);
	pthread_mutex_unlock(&philo->forks[1]);
	sleep_routine(philo);
	return (0);
}

static int	think_routine(t_philo *philo)
{
	size_t	time_to_think;

	pthread_mutex_lock(&philo->meal_time_lock);
	time_to_think = (philo->options.p_ttd - (get_curr_time() - philo->last_meal) 
			- philo->options.p_tte) / 2;
	pthread_mutex_unlock(&philo->meal_time_lock);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think == 0)
		time_to_think = 1;
	if (time_to_think > 600)
		time_to_think = 200;
	write_action(philo, EAT, philo->id);
	sleep_routine(philo);
}

void	*philo_routine(void *data)
{
	t_philo *philo;
	int 	i;

	write(1, "A\n", 2);
	philo = data;
	philo_hold(philo);
	if (philo->id % 2)
		think_routine(philo);
	i = 1;
	while (i)
	{
		pthread_mutex_lock(&philo->run_lock);
		if (philo->run_flag == false)
			return (NULL);
		pthread_mutex_unlock(&philo->run_lock);
		eat_routine(philo);
		think_routine(philo);
	}
}
