/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:18:31 by mandre            #+#    #+#             */
/*   Updated: 2025/09/26 20:28:06 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think_routine(philo_t *philo, bool silent)
{
	if (!silent)
		print_states(philo, PHILO_THINKS);
}

static void	eating_routine(philo_t *philo, bool silent)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->l_fork);
		print_states(philo, GOT_L_FORK);
		pthread_mutex_lock(philo->r_fork);
		print_states(philo, GOT_R_FORK);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_states(philo, GOT_R_FORK);
		pthread_mutex_lock(philo->l_fork);
		print_states(philo, GOT_L_FORK);
	}
	if (!silent)
		print_states(philo, PHILO_EATS);
	ft_usleep(philo->time_to_eat);
	philo->time_last_meal = get_curr_time();
	philo->number_of_meals += 1;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	think_routine(philo, silent);
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
void	*routine(void *data)
{
	philo_t *philo;

	philo = (philo_t *)data;
	if (philo->id % 2)
		sleep_think_routine(philo, false);
	while (philo->run_philo)
	{
		eating_routine(philo, false);
		sleep_think_routine(philo, false);
	}
}
