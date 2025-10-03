/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:47:02 by mandre            #+#    #+#             */
/*   Updated: 2025/10/02 20:00:09 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief This fills the options_struct containing the
/// parameters set by the user via argv 
static void	fill_options(t_meta *meta, t_philo *philo)
{
	philo->options.p_num = meta->options.p_num;
	philo->options.p_ttd = meta->options.p_ttd;
	philo->options.p_tte = meta->options.p_tte;
	philo->options.p_tts = meta->options.p_tts;
	philo->options.p_mec = meta->options.p_mec;
	philo->options.start_time = meta->options.start_time;
}

int	init_philo(t_meta *meta, t_philo *philo, unsigned int id)
{
	philo->id = id;
	philo->meal_count = 0;
	philo->alive = true;
	fill_options(meta, philo);
	assign_forks(meta, philo);
	philo->sync_lock_ptr = &meta->sync_lock;
	philo->sync_flag_ptr = &meta->sync_flag;
	philo->write_lock_ptr = &meta->write_lock;
	philo->run_lock_ptr = &meta->run_lock;
	philo->run_flag_ptr = &meta->run_flag;
	if (pthread_mutex_init(&philo->meal_count_lock, NULL) != 0)
		return (throw_error(INIT_MUTEX_FAILED));
	if (pthread_mutex_init(&philo->meal_time_lock, NULL) != 0)
		return (throw_error(INIT_MUTEX_FAILED));
	if (pthread_mutex_init(&philo->alive_lock, NULL))
		return (throw_error(INIT_MUTEX_FAILED));
	return (0);
}

/// @brief Initializes the locks in the
/// meta struct 
static int	create_meta_locks(t_meta *meta)
{
	if (pthread_mutex_init(&meta->sync_lock, NULL) != 0)
		return (throw_error(INIT_MUTEX_FAILED));
	if (pthread_mutex_init(&meta->write_lock, NULL))
		return (throw_error(INIT_MUTEX_FAILED));
	if (pthread_mutex_init(&meta->run_lock, NULL))
		return (throw_error(INIT_MUTEX_FAILED));
	return (0);
}

void	init_meta(t_meta *meta)
{
	meta->sync_flag = false;
	meta->run_flag = true;
	meta->options.start_time = get_curr_time();
	create_meta_locks(meta);
	create_total_forks(meta);
}
