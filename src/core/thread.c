/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:21:55 by mandre            #+#    #+#             */
/*   Updated: 2025/09/28 15:27:22 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief Joins/terminates the threads/philos
/// And calls fnc to destroy mutexes 
/// @return 0 on Success, Error Code on Error
int	join_philos(t_meta *meta)
{
	int i;

	i = 0;
	while (i < meta->option.p_num)
	{
		if (pthread_join((meta->philo[i]).thread, NULL) != 0)
			return(throw_error(THREAD_JOIN_FAILED));
		i++;
	}
}

/// @brief Creates the threads/philos inside a while loop
/// the provided amount of times
/// @param meta Meta Struct conatining
/// all important parameters
/// @return 0 on Success, Error Code on error
int	init_philos(t_meta *meta)
{
	int	i;

	init_meta(meta);
	i = 0;
	while (i < meta->option.p_num)
	{
		if (pthread_create(&(meta->philo[i]).thread, NULL, &philo_routine, NULL) != 0)
			return (throw_error(THREAD_CREATION_FAILED));
		i++;
	}
	philo_start(meta);
	return (0);
}
