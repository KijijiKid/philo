/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:01:19 by mandre            #+#    #+#             */
/*   Updated: 2025/09/29 15:59:22 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	write_action(pthread_mutex_t write_lock,t_action action, unsigned int id, bool display)
{
	pthread_mutex_lock(&write_lock);
	char	*curr_time_s;
	char	*id_s;

	curr_time_s = ft_ltoa(get_curr_time());
	id_s = ft_ltoa(id);
	if (action == SLEEP)
	{
		write(1, curr_time_s, ft_strlen(curr_time_s));
		write(1, "\n", 1);
		write(1, id_s, ft_strlen(id_s));
		write(1, "\n", 1);
		//Do this
	}
	// else if (action == THINK)
	// 	//Do this
	// else if (action == EAT)
	// 	//DO this
	free(curr_time_s);
	pthread_mutex_unlock(&write_lock);
}
