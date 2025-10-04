/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:47:02 by mandre            #+#    #+#             */
/*   Updated: 2025/10/04 19:39:22 by mandre           ###   ########.fr       */
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
	philo->options.start_time = &meta->start_time;
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
	philo->meal_count_lock = sem_open("meal_count_lock", O_CREAT);
	philo->meal_time_lock = sem_open("meal_time_lock", O_CREAT);
	philo->alive_lock = sem_open("alive_lock", O_CREAT);
	if (philo->meal_count_lock == SEM_FAILED)
		return (throw_error(SEM_CREATION));
	if (philo->meal_time_lock == SEM_FAILED)
		return (throw_error(SEM_CREATION));
	if (philo->alive_lock == SEM_FAILED)
		return (throw_error(SEM_CREATION));
	return (0);
}

/// @brief Initializes the locks in the
/// meta struct 
static int	create_meta_locks(t_meta *meta)
{
	meta->sync_lock = sem_open("sync_lock", O_CREAT);
	meta->write_lock = sem_open("write_lock", O_CREAT);
	meta->run_lock = sem_open("run_lock", O_CREAT);
	if (meta->sync_lock == SEM_FAILED)
		return (throw_error(SEM_CREATION));
	if (meta->write_lock == SEM_FAILED)
		return (throw_error(SEM_CREATION));
	if (meta->run_lock == SEM_FAILED)
		return (throw_error(SEM_CREATION));
	return (0);
}

void	init_meta(t_meta *meta)
{
	meta->sync_flag = false;
	meta->run_flag = true;
	meta->options.start_time = 0;
	meta->forks = sem_open("forks", O_CREAT);
	create_meta_locks(meta);
}
