/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:18:31 by mandre            #+#    #+#             */
/*   Updated: 2025/09/24 20:14:44 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int i = 0;

/// @brief Here i set the routine a philosopher has
/// eating, sleeping and thinking
void	*routine(philo_t *philo)
{
	pthread_mutex_lock(philo->r_fork);
		i++;
	pthread_mutex_unlock(philo->r_fork);
	printf("ALO\n");
	printf("%d\n", i);
	return (NULL);
}