/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:47:02 by mandre            #+#    #+#             */
/*   Updated: 2025/10/07 17:47:09 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	philo->alive = true;
	fill_options(meta, philo);
	philo->sync_flag_ptr = &meta->sync_flag;
	philo->write_sem = meta->write_sem;
	philo->run_flag_ptr = &meta->run_flag;
	philo->forks = meta->forks;
	philo->fork_flag_ptr = &meta->fork_flag;
	philo->meal_count = 0;
	return (0);
}

void	init_meta(t_meta *meta)
{
	meta->sync_flag = false;
	meta->run_flag = true;
	meta->write_sem = sem_open("write_sem", O_CREAT | O_EXCL,
			S_IRUSR | S_IWUSR, 1);
	meta->options.start_time = 0;
	meta->fork_flag = 0;
	meta->forks = sem_open("forks", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR,
			meta->options.p_num);
}
