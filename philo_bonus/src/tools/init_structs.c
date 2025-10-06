/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:47:02 by mandre            #+#    #+#             */
/*   Updated: 2025/10/06 17:45:29 by mandre           ###   ########.fr       */
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
	philo->sync_flag_ptr = &meta->sync_flag;
	philo->write_flag_ptr = &meta->write_flag;
	philo->run_flag_ptr = &meta->run_flag;
	philo->run_flag_ptr = &meta->run_flag;
	philo->forks = meta->forks;
	philo->fork_flag_ptr = &meta->fork_flag;
	philo->meal_count_lock = sem_open(set_local_sem_name("meal_count_lock",
				id), O_CREAT, 0666, 1);
	philo->meal_time_lock = sem_open(set_local_sem_name("meal_time_lock",
				id), O_CREAT, 0666, 1);
	if (philo->meal_count_lock == SEM_FAILED)
		return (throw_error(SEM_CREATION));
	if (philo->meal_time_lock == SEM_FAILED)
		return (throw_error(SEM_CREATION));
	return (0);
}


void	init_meta(t_meta *meta)
{
	meta->sync_flag = false;
	meta->run_flag = true;
	meta->write_flag = false;
	meta->options.start_time = 0;
	meta->fork_flag = 0;
	meta->forks = sem_open("forks", O_CREAT, S_IRUSR | S_IWUSR,
			meta->options.p_num);
}
