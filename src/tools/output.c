/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:01:19 by mandre            #+#    #+#             */
/*   Updated: 2025/09/30 11:48:30 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	write_action(t_philo *philo, t_action action, unsigned int id)
{
	bool	write;
	// size_t	time;

	write = true;
	pthread_mutex_lock(&philo->run_lock);
	if (*philo->run_flag == false)
		return 1;
	pthread_mutex_unlock(&philo->run_lock);
	pthread_mutex_lock(&philo->write_lock);
	if (action == SLEEP && write)
		printf("%ld %d is sleeping\n", get_curr_time() - philo->options.start_time, id);
	else if (action == THINK && write)
		printf("%ld %d is thinking\n", get_curr_time() - philo->options.start_time, id);
	else if (action == EAT && write)
		printf("%ld %d is eating\n", get_curr_time() - philo->options.start_time, id);
	else if (action == T_FORK && write)
		printf("%ld %d has taken a fork\n", get_curr_time() - philo->options.start_time, id);
	else if  (action == P_IS_DEAD && write)
		printf("%ld %d is dead\n", get_curr_time() - philo->options.start_time, id);
	else if (action == P_ARE_FULL && write)
		printf("Philos are full\n");
	pthread_mutex_unlock(&philo->write_lock);
	return (0);
}
