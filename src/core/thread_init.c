/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:42:10 by mandre            #+#    #+#             */
/*   Updated: 2025/09/22 19:11:44 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int a = 0;
pthread_mutex_t mutex;

void	*routine(void)
{
	// sleep(1);
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
	philo_meta->thread = malloc(sizeof(pthread_t) * philo_meta->philosophers_count );
	i = 0;
	while (i < philo_meta->philosophers_count)
	{
		if (pthread_create(&philo_meta->thread[i], NULL, ((void *)routine), NULL) != 0)
			perror("Creation Failed"); //Implement verbose -> TODO
		i++;
	}
	i--;
	while (0 <= i)
	{
		sleep(1);
		printf("%d\n", i);
		if (pthread_join(philo_meta->thread[i], NULL) != 0)
			perror("Join Failed"); //Implement verbose -> TODO
		printf("Thread joined\n");
		i--;
	}
	pthread_mutex_destroy(&mutex);
	// i--;
	// while (0 <= i)
	// {
	// 	printf("freed\n");
	free(&philo_meta->thread[0]);
	// 	i--;
	// }
	return (0);
}
