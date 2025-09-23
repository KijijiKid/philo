/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:35:30 by mandre            #+#    #+#             */
/*   Updated: 2025/09/23 19:59:23 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief This function manely mallocs as many philo_t structs as specified in argc[1]
/// and sets the dead flag to false
/// @return 0 on success and -1 on failure
int	init_structs(t_meta *philo_meta)
{
	philo_meta->philo = malloc(sizeof(philo_t) * philo_meta->philosophers_count);
	if (!philo_meta->philo)
		return (-1);
	philo_meta->dead = false;
	return (0);
}
