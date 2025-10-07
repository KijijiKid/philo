/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:01:19 by mandre            #+#    #+#             */
/*   Updated: 2025/10/07 17:27:50 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	print_status(t_philo *philo, char *str)
{
	sem_wait(philo->write_sem);
	printf("%ld %d %s\n", get_curr_time() - *(philo->options.start_time),
		philo->id + 1, str);
	sem_post(philo->write_sem);
}

int	write_action(t_philo *philo, t_action action, bool visible)
{
	bool	run;

	run = *(philo->run_flag_ptr);
	if (!run || !philo->alive)
		return (0);
	if (action == SLEEP && visible)
		print_status(philo, "is sleeping");
	else if (action == EAT && visible)
		print_status(philo, "is eating");
	else if (action == THINK && visible)
		print_status(philo, "is thinking");
	else if (action == T_FORK && visible)
		print_status(philo, "taken fork");
	return (0);
}
