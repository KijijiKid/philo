/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:01:19 by mandre            #+#    #+#             */
/*   Updated: 2025/10/01 14:03:45 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status(t_philo *philo, char *str)
{
	printf("%ld %d %s\n", get_curr_time() - philo->options.start_time,
		philo->id, str);
}

int	write_action(t_philo *philo, t_action action, unsigned int id)
{
	pthread_mutex_lock(&philo->write_lock);
	pthread_mutex_lock(&philo->run_lock);
	if (*philo->run_flag == false)
	{
		pthread_mutex_unlock(&philo->write_lock);
		pthread_mutex_unlock(&philo->run_lock);
		return 1;
	}
	pthread_mutex_unlock(&philo->run_lock);
	if (action == SLEEP)
		print_status(philo, "is sleeping");
	else if (action == THINK)
		print_status(philo, "is thinking");
	else if (action == EAT)
		print_status(philo, "is eating");
	else if (action == T_FORK)
		print_status(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->write_lock);
	return (0);
}
