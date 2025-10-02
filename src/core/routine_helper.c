/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:09:23 by mandre            #+#    #+#             */
/*   Updated: 2025/10/02 16:18:05 by mandre           ###   ########.fr       */
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
	size_t n = get_curr_time();
	printf("%ld\n", n - last_meal);
	if (philo->options.p_ttd <= get_curr_time() - last_meal)
	{
		pthread_mutex_lock(&philo->alive_lock_ptr);
		philo->alive = false;
		pthread_mutex_unlock(&philo->alive_lock_ptr);
		return (false);
	}
	return (true);
}

void	set_first_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = get_curr_time();
	pthread_mutex_unlock(&philo->meal_time_lock);
}
