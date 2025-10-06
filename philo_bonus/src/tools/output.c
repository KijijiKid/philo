/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:01:19 by mandre            #+#    #+#             */
/*   Updated: 2025/10/06 17:48:11 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status(t_philo *philo, char *str)
{
	while(*philo->write_flag_ptr)
		continue ;
	*philo->write_flag_ptr = true;
	printf("%ld %d %s\n", get_curr_time() - *(philo->options.start_time),
		philo->id + 1, str);
	*philo->write_flag_ptr = false;
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
