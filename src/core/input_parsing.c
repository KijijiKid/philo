/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:20:39 by mandre            #+#    #+#             */
/*   Updated: 2025/09/22 15:28:01 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int input_parsing(int argc, char **argv, t_meta *philo_meta)
{
	if (argc == 5)
	{
		philo_meta->philosophers_count = ft_atoi(argv[1]);
		philo_meta->time_to_die = str_to_double(argv[2]);
		philo_meta->time_to_eat = str_to_double(argv[3]);
		philo_meta->time_to_sleep = str_to_double(argv[4]);
		philo_meta->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		return (0);
	}
	return (-1);
}