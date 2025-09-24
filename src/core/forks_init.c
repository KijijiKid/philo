/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:41:09 by mandre            #+#    #+#             */
/*   Updated: 2025/09/24 11:18:52 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_forks(t_meta *philo_meta, philo_t *philo)
{
	int	curr_philo_id;

	curr_philo_id = philo->id;
	philo->r_fork = &(philo_meta->total_forks)[curr_philo_id - 1];
	if (curr_philo_id == 0)
		philo->l_fork = &(philo_meta->total_forks)[philo_meta->philosophers_count - 1];
	else
		philo->l_fork = &(philo_meta->total_forks)[curr_philo_id - 2];
}

/// @brief Creates as many forks as they are philosophers
/// @param philo 
void	init_forks(t_meta *philo_meta)
{
	int i;

	i = 0;
	philo_meta->total_forks = malloc(sizeof(pthread_mutex_t) * philo_meta->philosophers_count);
	while (i <= philo_meta->philosophers_count)
	{
		if (pthread_mutex_init(&(philo_meta->total_forks)[i], NULL) != 0)
		{
			write(2, MUTEX_ERROR, 31);
			return ;
		}
		i++;
	}
}
