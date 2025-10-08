/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:21:56 by mandre            #+#    #+#             */
/*   Updated: 2025/10/08 16:13:36 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	sleep_routine(t_philo *philo, bool write)
{
	if (!is_alive(philo))
		return (1);
	write_action(philo, SLEEP, write);
	ft_usleep(philo->options.p_tts);
	return (0);
}

static int	think_routine(t_philo *philo, bool write)
{
	long	time_to_think;

	if (!is_alive(philo))
		return (1);
	write_action(philo, THINK, write);
	return (0);
}

static int	eat_routine(t_philo *philo, bool write)
{
	if (!is_alive(philo))
		return (1);
	while (philo->options.p_num - 1 <= *philo->fork_flag_ptr)
		continue ;
	*philo->fork_flag_ptr += 2;
	sem_wait(philo->forks);
	sem_wait(philo->forks);
	write_action(philo, T_FORK, write);
	write_action(philo, T_FORK, write);
	write_action(philo, EAT, write);
	set_time_count(philo);
	ft_usleep(philo->options.p_tte);
	sem_post(philo->forks);
	sem_post(philo->forks);
	*philo->fork_flag_ptr -= 2;
	sleep_routine(philo, write);
	return (0);
}

static int	lone_philo(t_philo *philo)
{
	if (philo->options.p_num == 1)
	{
		printf("%ld %d philo died\n", *philo->options.start_time
			- get_curr_time(), philo->id + 1);
		return (1);
	}
	return (0);
}

void	*routine(void *data)
{
	t_philo	*philo;
	bool	run;
	bool	write;

	philo = (t_philo *)data;
	if (lone_philo(philo))
		return (NULL);
	philo_hold(philo);
	set_first_meal_time(philo);
	if (philo->id % 2)
		sleep_routine(philo, false);
	write = true;
	while (1)
	{
		run = *(philo->run_flag_ptr);
		if (!run || !philo->alive)
			break ;
		if (eat_routine(philo, true))
			write = false;
		think_routine(philo, write);
	}
	return (NULL);
}
