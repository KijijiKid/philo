/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:25:03 by mandre            #+#    #+#             */
/*   Updated: 2025/09/22 16:07:36 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_meta  philo_meta;

	if (argc == 6 || argc == 5)
	{
		if (input_parsing(argc, argv, &philo_meta) == 1)
			write_error(2);
		// printf("%d\n", philo_meta.philosophers_count);
		// printf("%f\n", philo_meta.time_to_die);
		// printf("%f\n", philo_meta.time_to_eat);
		// printf("%f\n", philo_meta.time_to_sleep);
		// printf("%d\n", philo_meta.number_of_times_each_philosopher_must_eat);
	}
	else 
		write_error(1);
}