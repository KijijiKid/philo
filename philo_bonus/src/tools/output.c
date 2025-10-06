/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:01:19 by mandre            #+#    #+#             */
/*   Updated: 2025/10/06 16:09:50 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status(t_philo *philo, char *str)
{
	sem_wait(philo->write_lock_ptr);
	printf("%ld %d %s %d\n", get_curr_time() - *(philo->options.start_time),
		philo->id + 1, str, philo->meal_count);
	sem_post(philo->write_lock_ptr);
}

int	write_action(t_philo *philo, t_action action, bool visible)
{
	bool	run;

	sem_wait(philo->run_lock_ptr);
	run = *(philo->run_flag_ptr);
	sem_post(philo->run_lock_ptr);
	if (!run || !philo->alive)
		return (0);
	if (action == SLEEP && visible)
		print_status(philo, "is sleeping");
	else if (action == EAT && visible)
		print_status(philo, "is eating");
	else if (action == THINK && visible)
		print_status(philo, "is thinking");
	else if (action == T_FORK && visible)
		print_status(philo, "taken fork");
	return (0);
}
