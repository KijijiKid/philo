/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:55:45 by mandre            #+#    #+#             */
/*   Updated: 2025/10/02 13:45:59 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_monitor(t_meta *meta)
{

	int i = 0;
	while (i < 5)
	{
		i++;
		sleep(1);
	}
	pthread_mutex_lock(&meta->run_lock);
	meta->run_flag =  false;
	pthread_mutex_unlock(&meta->run_lock);
}
