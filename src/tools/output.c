/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:01:19 by mandre            #+#    #+#             */
/*   Updated: 2025/10/02 20:38:49 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->write_lock_ptr);
	printf("%ld %d %s\n", get_curr_time() - philo->options.start_time,
		philo->id + 1, str);
	pthread_mutex_unlock(philo->write_lock_ptr);
}

int	write_action(t_philo *philo, t_action action)
{
	if (action == SLEEP)
		print_status(philo, "is sleeping");
	else if (action == EAT)
		print_status(philo, "is eating");
	else if (action == THINK)
		print_status(philo, "is thinking");
	else if (action == T_FORK)
		print_status(philo, "has taking fork");
	return (0);
}
