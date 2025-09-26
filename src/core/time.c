/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:29:09 by mandre            #+#    #+#             */
/*   Updated: 2025/09/26 19:27:15 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_curr_time(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, TIME_ERROR, 22);
	return(time.tv_sec * 1000 + time.tv_usec / 1000);
}

/// @brief Just a more accurate usleep fucntion
/// @param ms Milliseconds to sleep
/// @return 
void ft_usleep(size_t ms)
{
	int start;
	
	start = get_curr_time();
	while (get_curr_time() - start < ms)
		usleep(500);
}
