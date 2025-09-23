/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:51:39 by mandre            #+#    #+#             */
/*   Updated: 2025/09/23 18:10:48 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clean_all(t_meta *philo_meta)
{
	int	i;

	i = 0;
	while (i < philo_meta->philosophers_count)
	{
		if (pthread_join((philo_meta->philo)[i].thread, NULL) != 0)
			perror("Creation Failed"); //Implement verbose -> TODO
		free(&(philo_meta->philo)[i]);
		i++;
	}
	return (0);
}
