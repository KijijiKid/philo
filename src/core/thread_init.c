/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:42:10 by mandre            #+#    #+#             */
/*   Updated: 2025/09/23 18:11:17 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int a = 0;
pthread_mutex_t mutex;

void	*routine(void)
{
	pthread_mutex_lock(&mutex);
	printf("%d\n", a);
	a++;
	printf("Thread Created\n");
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int	create_threads(t_meta *philo_meta)
{
	int	i;

	pthread_mutex_init(&mutex, NULL);
	i = 1;
	while (i < philo_meta->philosophers_count)
	{
		philo_meta->philo[i].id = i + 1; // Increment by one to not have Philo with Id 0
		if (pthread_create(&(philo_meta->philo)[i].thread, NULL, ((void *)routine), NULL) != 0)
			perror("Creation Failed"); //Implement verbose -> TODO
		i++;
	}
	return (0);
}
