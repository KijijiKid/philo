/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:27:58 by mandre            #+#    #+#             */
/*   Updated: 2025/09/28 15:29:10 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_mutexes(t_meta *meta)
{
	if (pthread_mutex_destroy(&meta->wait_lock) != 0)
		return(throw_error(DSTRY_MUTEX_FAILED));
	if (pthread_mutex_destroy(&meta->write_lock) != 0)
		return(throw_error(DSTRY_MUTEX_FAILED));
	return (0);
}