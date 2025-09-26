/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:17:41 by mandre            #+#    #+#             */
/*   Updated: 2025/09/26 16:15:43 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <sys/types.h>


bool	check_if_dead(t_meta *philo_meta)
{
	if (philo_meta->dead)
		return ;
	return (false);
}

/// @brief The monitor init initializes a endless while loop
/// that checks	if a philiosopher is dead -> if so the flag 
/// for philo is dead turns true. The other case is when 
/// all of the philosophers ate enough
void	*monitor_init(void *data)
{
	t_meta *philo_meta;

	philo_meta = (t_meta *)data;
	while (1)
	{
		if (check_if_dead(philo_meta))
			break ;
		if (check_if_meals(philo_meta))
			break ;
	}
	stop_philos(philo_meta);
	return (NULL);
}
