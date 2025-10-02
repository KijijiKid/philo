/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:09:23 by mandre            #+#    #+#             */
/*   Updated: 2025/10/02 15:17:50 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief Increments meal_count and sets last
/// meal time to current time.
/// Uses meal_time_lock and meal_count_lock
void	set_time_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = get_curr_time();
	pthread_mutex_unlock(&philo->meal_time_lock);
	pthread_mutex_lock(&philo->meal_count_lock);
	philo->meal_count =+ 1;
	pthread_mutex_unlock(&philo->meal_count_lock);
}

bool	is_alive(t_philo *philo)
{
	size_t	last_meal;

	pthread_mutex_lock(&philo->meal_time_lock);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->meal_time_lock);
	if (get_curr_time() - last_meal)
	{
		philo->alive = false;
		return (false);
	}
	return (true);
}
