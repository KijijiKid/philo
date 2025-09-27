/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:02:27 by mandre            #+#    #+#             */
/*   Updated: 2025/09/27 12:24:12 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	print_states(philo_t *philo, t_status status)
{
	pthread_mutex_lock(&philo->msg_lock);
	if (status == GOT_L_FORK || status == GOT_R_FORK)
		printf("%ld %d %s", get_curr_time(), philo->id, FORK_TAKEN);
	else if (status == PHILO_DEAD)
		printf("%ld %d %s", get_curr_time(), philo->id, DEAD_MSG);
	else if (status == PHILO_THINKS)
		printf("%ld %d %s", get_curr_time(), philo->id, IS_THINKING);
	else if (status == PHILO_SLEEPS)
		printf("%ld %d %s", get_curr_time(), philo->id, IS_SLEEPING);
	else if (status == PHILO_EATS)
		printf("%ld %d %s", get_curr_time(), philo->id, IS_EATING);
	else if (status == FORK_LAID_BACK)
		printf("%ld %d %s", get_curr_time(), philo->id, LAID_BACK);
	pthread_mutex_unlock(&philo->msg_lock);
}
