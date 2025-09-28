/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:32:55 by mandre            #+#    #+#             */
/*   Updated: 2025/09/28 15:00:59 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief Holds threads/philos in a while loop
/// as long as the others are not created (wait_flag == true)
static void	philo_hold(t_meta *meta)
{
	int i;

	i = 1;
	while (i)
	{
		pthread_mutex_lock(&meta->wait_lock);
		if (meta->wait_flag == false)
			i = 0;
		pthread_mutex_lock(&meta->wait_lock);
	}
}

void	*philo_routine(void *data)
{
	t_meta *meta;

	meta = data;
	philo_hold(meta);
	
	write(1, "ALLO\n", 5);
}
