/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:09:23 by mandre            #+#    #+#             */
/*   Updated: 2025/10/06 16:51:07 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	try_grab(t_philo *philo)
// {
// 	sem_wait(philo->forks);

// }

/// @brief Increments meal_count and sets last
/// meal time to current time.
/// Uses meal_time_lock and meal_count_lock
void	set_time_count(t_philo *philo)
{
	sem_wait(philo->meal_time_lock);
	philo->last_meal = get_curr_time();
	sem_post(philo->meal_time_lock);
	sem_wait(philo->meal_count_lock);
	philo->meal_count += 1;
	sem_post(philo->meal_count_lock);
}

bool	is_alive(t_philo *philo)
{
	size_t	last_meal;
	size_t	sol;

	sem_wait(philo->meal_time_lock);
	last_meal = philo->last_meal;
	sem_post(philo->meal_time_lock);
	sol = get_curr_time() - last_meal;
	if (philo->options.p_ttd <= sol)
	{
		philo->alive = false;
		return (false);
	}
	return (true);
}

void	set_first_meal_time(t_philo *philo)
{
	sem_wait(philo->meal_time_lock);
	philo->last_meal = get_curr_time();
	sem_post(philo->meal_time_lock);
}
