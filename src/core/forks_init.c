/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:41:09 by mandre            #+#    #+#             */
/*   Updated: 2025/09/24 10:45:40 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/// @brief Creates as many forks as they are philosophers
/// @param philo 
void	init_forks(t_meta *philo_meta)
{
	int i;

	i = 0;
	while (i <= philo_meta->philosophers_count)
	{
		if (pthread_mutex_init(&(philo_meta->total_forks)[i], NULL) != 0)
			//Error MSG
		i++;
	}
}
