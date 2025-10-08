/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:09:23 by mandre            #+#    #+#             */
/*   Updated: 2025/10/08 16:57:46 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/// @brief Increments meal_count and sets last
/// meal time to current time.
/// Uses meal_time_lock and meal_count_lock
void	set_time_count(t_philo *philo)
{
	philo->last_meal = get_curr_time();
	philo->meal_count += 1;
}

bool	is_alive(t_philo *philo)
{
	size_t	last_meal;
	size_t	sol;

	last_meal = philo->last_meal;
	if (last_meal == 0)
		return (true);
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
	philo->last_meal = get_curr_time();
}
