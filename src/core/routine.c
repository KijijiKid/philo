/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:18:31 by mandre            #+#    #+#             */
/*   Updated: 2025/09/23 20:27:42 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/// @brief Here i set the routine a philosopher has
/// eating, sleeping and thinking
void	*routine(philo_t *philo)
{
	printf("Hello from thread %zu\n", philo->id);
	return NULL;
}