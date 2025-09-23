/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:25:03 by mandre            #+#    #+#             */
/*   Updated: 2025/09/23 19:39:45 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_meta	philo_meta;

	if (argc == 6 || argc == 5)
	{
		if (input_parsing(argc, argv, &philo_meta) == 1)
			write_error(2);
		init_structs(&philo_meta);
		create_threads(&philo_meta);
		sleep(2);
		clean_all(&philo_meta);
	}
	else 
		write_error(1);
}
