/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:02:27 by mandre            #+#    #+#             */
/*   Updated: 2025/09/26 18:02:28 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_states(philo_t *philo, t_status status)
{
	printf ("%d ", get_curr_time());
	if (status == GOT_L_FORK || status == GOT_R_FORK)
		printf("%d %s", philo->id, FORK_TAKEN);
	else if (status == PHILO_DEAD)
		printf("%d %s", philo->id, DEAD_MSG);
	else if (status == PHILO_THINKS)
		printf("%d %s", philo->id, IS_THINKING);
	else if (status == PHILO_SLEEPS)
		printf("%d %s", philo->id, IS_SLEEPING);
	else if (status == PHILO_EATS)
		printf("%d %s", philo->id, IS_EATING);
}
