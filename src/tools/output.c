/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:01:19 by mandre            #+#    #+#             */
/*   Updated: 2025/09/29 18:15:21 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	write_action(t_philo *philo, t_action action, unsigned int id, bool display)
{
	// pthread_mutex_lock(&write_lock);
	char	*curr_time_s;
	char	*id_s;

	pthread_mutex_lock(&philo->write_lock);
	curr_time_s = ft_ltoa(get_curr_time() - philo->options.start_time);
	id_s = ft_ltoa(id);
	if (action == SLEEP)
	{
		printf("%s %s is sleeping\n", curr_time_s, id_s);
	}
	else if (action == THINK)
		printf("%s %s is thinking\n", curr_time_s, id_s);
	else if (action == EAT)
		printf("%s %s is eating\n", curr_time_s, id_s);
	else if (action == T_FORK)
		printf("%s %s has taken a fork\n", curr_time_s, id_s);
	else if  (action == P_IS_DEAD)
		printf("%s %s is dead\n", curr_time_s, id_s);
	else if (action == P_ARE_FULL)
		printf("Philos are full\n");
	free(curr_time_s);
	pthread_mutex_unlock(&philo->write_lock);
}
