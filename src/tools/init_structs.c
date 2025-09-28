/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:04:32 by mandre            #+#    #+#             */
/*   Updated: 2025/09/28 17:57:39 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief Inita
/// @param meta 
/// @return 0 or error code
static int	init_mutexes(t_meta *meta)
{
	if (pthread_mutex_init(&meta->wait_lock, NULL) != 0)
		return(throw_error(INIT_MUTEX_FAILED));
	if (pthread_mutex_init(&meta->write_lock, NULL) != 0)
		return(throw_error(INIT_MUTEX_FAILED));
	return (0);
}

/// @brief This assigns the variables of each philo.
/// So Id, L/R Fork and macros(tte, ttd, tts, [tpme])
int	assign_philos(t_meta *meta, t_philo *philo, unsigned int id)
{
	philo->id = id;
	philo->options.p_mec = meta->options.p_mec;
	philo->options.p_num = meta->options.p_num;
	philo->options.p_ttd = meta->options.p_ttd;
	philo->options.p_tte = meta->options.p_tte;
	philo->options.p_tts = meta->options.p_tts;
	philo->last_meal = 0;
	if (pthread_mutex_init(&philo->meal_time_lock, NULL) != 0)
		return(throw_error(INIT_MUTEX_FAILED));
	return (0);
}

/// @brief Sets Flags and starting params of the meta_structs.
/// As well as initalizing the mutexes.
/// @return Returns Error Code if something fails or 0
/// on success
int	init_meta(t_meta *meta)
{
	meta->wait_flag = true;
	meta->run_flag = true;
	return (init_mutexes(meta));
}
