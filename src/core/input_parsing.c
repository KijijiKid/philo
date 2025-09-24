/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:20:39 by mandre            #+#    #+#             */
/*   Updated: 2025/09/24 19:04:05 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/// @brief This function stores all the values in the right converted format
/// in the meta_struct
int	input_parsing(int argc, char **argv, t_meta *philo_meta)
{
	if (argc == 5)
	{
		philo_meta->philosophers_count = ft_atoi(argv[1]);
		philo_meta->time_to_die = ft_atoi(argv[2]);
		philo_meta->time_to_eat = ft_atoi(argv[3]);
		philo_meta->time_to_sleep = ft_atoi(argv[4]);
		philo_meta->number_of_times_each_philosopher_must_eat = 10;
	}
	else if (argc == 6)
	{
		philo_meta->philosophers_count = ft_atoi(argv[1]);
		philo_meta->time_to_die = ft_atoi(argv[2]);
		philo_meta->time_to_eat = ft_atoi(argv[3]);
		philo_meta->time_to_sleep = ft_atoi(argv[4]);
		philo_meta->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	}
	if (!(1 < philo_meta->philosophers_count && philo_meta->philosophers_count <= 200)
		|| !(0 < philo_meta->time_to_die && philo_meta->time_to_die < 1000)
		|| !(0 < philo_meta->time_to_eat && philo_meta->time_to_eat < 1000)
		|| !(0 < philo_meta->time_to_sleep && philo_meta->time_to_sleep < 1000) 
		|| philo_meta->number_of_times_each_philosopher_must_eat <= 0)
		return (1);
	return (0);
}
