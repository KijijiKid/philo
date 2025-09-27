/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:45:16 by mandre            #+#    #+#             */
/*   Updated: 2025/09/27 19:46:55 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:29:09 by mandre            #+#    #+#             */
/*   Updated: 2025/09/23 19:57:16 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief Returns a unsigned long
/// of the seconds since Year stared 
size_t	get_curr_time(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "Schaise\n", 8);
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

char	*formated_time(void)
{
	char *formatted_time;
	struct timeval time;
	int seconds_in_day;
	int	hours;
	int min;
	int sec;
	int ms;
	
	if (gettimeofday(&time, NULL) == -1)
		write(2, "Schaise2\n", 9);
	seconds_in_day = time.tv_sec % 86400;
	hours	= seconds_in_day / 3600;
	min		= (seconds_in_day % 3600) / 60;
	sec		= seconds_in_day % 60;
	ms		= time.tv_usec / 1000;
	printf("%d:%d:%d:%d", hours, min, sec, ms);
	return (NULL);
}
