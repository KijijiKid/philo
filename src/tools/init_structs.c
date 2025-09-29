/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:04:32 by mandre            #+#    #+#             */
/*   Updated: 2025/09/29 20:46:07 by mandre           ###   ########.fr       */
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
	if (pthread_mutex_init(&meta->run_lock, NULL) != 0)
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
	philo->last_meal = get_curr_time();
	philo->total_meals = 0;
	philo->run_lock = meta->run_lock;
	philo->run_flag = &meta->run_flag;
	philo->wait_lock = meta->wait_lock;
	philo->wait_flag = &meta->wait_flag;
	philo->write_lock = meta->write_lock;
	philo->options.start_time = meta->start_time;
	if (pthread_mutex_init(&philo->meal_time_lock, NULL) != 0)
		return(throw_error(INIT_MUTEX_FAILED));
	if (pthread_mutex_init(&philo->meal_count_lock, NULL) != 0)
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
	meta->start_time = get_curr_time();
	if (init_forks(meta) != 0)
		return (1);
	return (init_mutexes(meta));
}
