/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:32:55 by mandre            #+#    #+#             */
/*   Updated: 2025/09/29 17:21:17 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat_routine(t_philo *philo)
{
	return (1);
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
