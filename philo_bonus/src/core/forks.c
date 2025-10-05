/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:48:36 by mandre            #+#    #+#             */
/*   Updated: 2025/10/05 18:51:12 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief Destroys the forks/mutexes in the
/// total forks array
int	clean_total_forks(t_meta *meta)
{
	unsigned int	i;

	i = 0;
	while (i < meta->options.p_num)
	{
		if (sem_close(meta->forks) != 0)
			return (throw_error(SEM_CLOSE_FAILED));
		if (sem_close(meta->philo[i].meal_count_lock) != 0)
			return (throw_error(SEM_CLOSE_FAILED));
		if (sem_close(meta->philo[i].meal_time_lock) != 0)
			return (throw_error(SEM_CLOSE_FAILED));
		if (sem_close(meta->philo[i].alive_lock) != 0)
			return (throw_error(SEM_CLOSE_FAILED));
		i++;
	}
	return (0);
}
