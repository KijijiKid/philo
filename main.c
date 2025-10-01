/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:25:03 by mandre            #+#    #+#             */
/*   Updated: 2025/10/01 16:08:11 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_meta meta;

	if (argc == 5 || argc == 6)
	{
		if (input_parsing(argc, argv, &meta) != 0)
			return(throw_error(WRONG_INPUT));
		else
		{
			
		}
	}
	else
		throw_error(WRONG_INPUT);
}
