/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:42:10 by mandre            #+#    #+#             */
/*   Updated: 2025/09/22 18:13:58 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void)
{
	printf("Thread Created\n");
	return (NULL);
}

int	create_threads(t_meta *philo_meta)
{
	int	i;

	philo_meta->thread = malloc(sizeof(pthread_t) * philo_meta->philosophers_count);
	i = 0;
	while (i < philo_meta->philosophers_count)
	{
		if (pthread_create(&philo_meta->thread[i], NULL, ((void *)routine), NULL) != 0)
			perror("Creation Failed"); //Implement verbose -> TODO
		i++;
	}
	// exit (1);
	i = 0;
	while (i < philo_meta->philosophers_count)
	{
		if (pthread_join(philo_meta->thread[i], NULL) != 0)
			perror("Join Failed"); //Implement verbose -> TODO
		// free(&philo_meta->thread[i]);
		i++;
	}
	return (0);
}
