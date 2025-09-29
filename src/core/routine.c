/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:32:55 by mandre            #+#    #+#             */
/*   Updated: 2025/09/29 18:15:25 by mandre           ###   ########.fr       */
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
	pthread_mutex_unlock(&philo->forks[0]);
	pthread_mutex_unlock(&philo->forks[1]);
	return (0);
}

static int	sleep_routine(t_philo *philo)
{
	write_action(philo , SLEEP, philo->id, true);
	ft_usleep(philo->options.p_tts);
}

void	*philo_routine(void *data)
{
	t_philo *philo;
	int 	i;

	philo = data;
	philo_hold(philo);
	sleep_routine(philo);
	i = 1;
	while (i)
	{
		pthread_mutex_lock(&philo->run_lock);
		if (*philo->run_flag == false)
			i = 0;
		pthread_mutex_unlock(&philo->run_lock);
		if (eat_routine(philo))
			break ;
		if (sleep_routine(philo))
			break ;
	}
}
