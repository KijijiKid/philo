/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:17:41 by mandre            #+#    #+#             */
/*   Updated: 2025/09/26 11:42:45 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief The monitor init initializes a endless while loop
/// that checks	if a philiosopher is dead -> if so the flag 
/// for philo is dead turns true. The other case is when 
/// all of the philosophers ate enough
void	*monitor_init(void)
{
	printf("Hello from Monitor\n");
	return (NULL);
}
