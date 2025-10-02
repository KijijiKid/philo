/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:29:09 by mandre            #+#    #+#             */
/*   Updated: 2025/10/02 19:13:07 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief Returns a unsigned long
/// of the seconds 
size_t	get_curr_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "Schaise\n", 8);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/// @brief Just a more accurate usleep fucntion
/// @param ms Milliseconds to sleep
/// @return 
void	ft_usleep(size_t ms)
{
	size_t	start;

	start = get_curr_time();
	while ((get_curr_time() - start) < ms)
		usleep(500);
}

// static void	append_int(char *buf, int *pos, unsigned int v)
// {
// 	char tmp[10];
//     int i = 0;
//     if (v == 0) {
//         buf[(*pos)++] = '0';
//         return;
//     }
//     while (v) {
//         tmp[i++] = (char)('0' + (v % 10));
//         v /= 10;
//     }
//     while (i-- > 0) {
//         buf[(*pos)++] = tmp[i];
//     }
// }

// char	*formated_time(void)
// {
// 	static char		time_arr[2048];
// 	struct timeval	time;
// 	unsigned int	seconds_in_day;
// 	unsigned int	hours;
// 	unsigned int	min;
// 	unsigned int	sec;
// 	unsigned int	ms;
// 	unsigned int	pos;
// 	if (gettimeofday(&time, NULL) == -1)
// 		throw_error(GET_TIME_FAILED);
// 	seconds_in_day = time.tv_sec % 86400;
// 	hours	= (seconds_in_day / 3600) + TIME_ZONE_OFFSET;
// 	min		= (seconds_in_day % 3600) / 60;
// 	sec		= seconds_in_day % 60;
// 	ms		= time.tv_usec / 1000;

// 	pos = 0;
// 	append_int(time_arr, &pos, hours);
// 	time_arr[pos++] = ':';
// 	append_int(time_arr, &pos, min);
// 	time_arr[pos++] = ':';
// 	append_int(time_arr, &pos, sec);
// 	time_arr[pos++] = ':';
// 	append_int(time_arr, &pos, ms);
// 	time_arr[pos++] = '\0';
// 	return (time_arr);
// }
