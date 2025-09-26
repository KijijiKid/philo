/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:18:31 by mandre            #+#    #+#             */
/*   Updated: 2025/09/26 18:17:33 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating_routine(philo_t *philo, bool silent)
{
	pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(&philo->r_fork);
	if (!silent)
		printf_states(philo, PHILO_EATS);
	ft_usleep(philo->time_to_eat);
	philo->time_last_meal = get_curr_time();
	philo->number_of_meals += 1;
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
}

static void	think_routine(philo_t *philo, bool silent)
{
	if (!silent)
		print_states(philo, PHILO_THINKS);
}

/// @brief This is the common sleep and after finishing 
/// think routine of the philosophers
/// @param philo 
/// @param silent If MSG get printed on the stdout
static void	sleep_think_routine(philo_t *philo, bool silent)
{
	if (!silent)
		print_states(philo, PHILO_SLEEPS);
	ft_usleep(philo->time_to_sleep);
	think_routine(philo, silent);
}

/// @brief Here i set the routine a philosopher has
/// eating, sleeping and thinking
void	*routine(philo_t *philo)
{
	if (philo->id % 2)
		sleep_think_routine(philo, true);
	while (1)
	{
		eating_routine(philo, false);
		sleep_think_routine(philo, false);
	}
}
