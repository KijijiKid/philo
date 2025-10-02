/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:21:51 by mandre            #+#    #+#             */
/*   Updated: 2025/10/02 15:12:23 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	clean_meta_locks(t_meta *meta)
{
	pthread_mutex_destroy(&meta->sync_lock);
	pthread_mutex_destroy(&meta->write_lock);
	pthread_mutex_destroy(&meta->run_lock);
}

void	clean_res(t_meta *meta)
{
	clean_total_forks(meta);
	clean_meta_locks(meta);
}
