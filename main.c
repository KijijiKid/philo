/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:25:03 by mandre            #+#    #+#             */
/*   Updated: 2025/09/26 12:22:03 by mandre           ###   ########.fr       */
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
		print_states(GOT_R_FORK);
		philo_meta.dead = false;
		create_threads(&philo_meta);
		clean_all(&philo_meta);
	}
	else 
		write_error(1);
}
