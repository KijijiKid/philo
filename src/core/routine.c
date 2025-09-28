/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:32:55 by mandre            #+#    #+#             */
/*   Updated: 2025/09/28 17:48:59 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	*philo_routine(void *data)
{
	t_meta *meta;
	int i;

	meta = data;
	philo_hold(meta);
	i = 1;
	while (i)
	{
		pthread_mutex_lock(&meta->run_lock);
		if (meta->run_flag == false)
			i = 0;
		pthread_mutex_unlock(&meta->run_lock);
		//Think & Sleep Routine
	}
}
