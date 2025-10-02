/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:47:02 by mandre            #+#    #+#             */
/*   Updated: 2025/10/02 14:55:21 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief This fills the options_struct containing the
/// parameters set by the user via argv 
static void	fill_options(t_meta *meta, t_philo *philo)
{
	philo->options.p_num = meta->options.p_num; //Number of philos
	philo->options.p_ttd = meta->options.p_ttd; //Time to die
	philo->options.p_tte = meta->options.p_tte; //Times to eat
	philo->options.p_tts = meta->options.p_tts; //Time to sleep
	philo->options.p_mec = meta->options.p_mec; //Must eat count
}

void	init_philo(t_meta *meta, t_philo *philo, unsigned int id)
{
	philo->id = id;

	//Fork Assigning
	assign_forks(meta, philo);
	//Shared 
	philo->sync_lock_ptr = &meta->sync_lock;
	philo->sync_flag_ptr = &meta->sync_flag;
	philo->write_lock_ptr = &meta->write_lock;
	philo->run_lock_ptr = &meta->run_lock;
	philo->run_flag_ptr =  &meta->run_flag;
}

/// @brief Initializes the locks in the
/// meta struct 
static void	create_meta_locks(t_meta *meta)
{
	pthread_mutex_init(&meta->sync_lock, NULL);
	pthread_mutex_init(&meta->write_lock, NULL);
	pthread_mutex_init(&meta->run_lock, NULL);
}

void	init_meta(t_meta *meta)
{
	meta->sync_flag = false;
	meta->run_flag = true;
	create_total_forks(meta);
}
