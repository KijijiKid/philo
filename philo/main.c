/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:25:03 by mandre            #+#    #+#             */
/*   Updated: 2025/10/07 18:25:13 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_meta	meta;

	if (argc == 5 || argc == 6)
	{
		if (input_parsing(argc, argv, &meta) != 0)
			return (throw_error(WRONG_INPUT));
		else
		{
			if (init_threads(&meta) != 0)
				return (1);
			if (init_monitor(&meta) != 0)
				return (2);
			if (clean_res(&meta) != 0)
				return (3);
		}
	}
	else
		throw_error(WRONG_INPUT);
}
