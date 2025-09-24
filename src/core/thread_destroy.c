/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:51:39 by mandre            #+#    #+#             */
/*   Updated: 2025/09/24 12:36:44 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clean_all(t_meta *philo_meta)
{
	int	i;

	i = 0;
	destroy_forks(philo_meta);
	while (i < philo_meta->philosophers_count)
	{
		if (pthread_join((philo_meta->philo)[i].thread, NULL) != 0)
			perror("Creation Failed"); //Implement verbose -> TODO
		i++;
	}
	free(&(philo_meta->philo)[0]);
	return (0);
}
