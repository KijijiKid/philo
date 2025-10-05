/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:56:13 by mandre            #+#    #+#             */
/*   Updated: 2025/10/05 19:03:50 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	input_parsing(int argc, char **argv, t_meta *philo_meta)
{
	if (argc == 5)
	{
		philo_meta->options.p_num = ft_atoi(argv[1]);
		philo_meta->options.p_ttd = ft_atoi(argv[2]);
		philo_meta->options.p_tte = ft_atoi(argv[3]);
		philo_meta->options.p_tts = ft_atoi(argv[4]);
		philo_meta->options.p_mec = 0;
	}
	else if (argc == 6)
	{
		philo_meta->options.p_num = ft_atoi(argv[1]);
		philo_meta->options.p_ttd = ft_atoi(argv[2]);
		philo_meta->options.p_tte = ft_atoi(argv[3]);
		philo_meta->options.p_tts = ft_atoi(argv[4]);
		philo_meta->options.p_mec = ft_atoi(argv[5]);
	}
	if (!(1 < philo_meta->options.p_num && philo_meta->options.p_num <= 200)
		|| !(0 < philo_meta->options.p_ttd && philo_meta->options.p_ttd < 1000)
		|| !(0 < philo_meta->options.p_tte && philo_meta->options.p_tte < 1000)
		|| !(0 < philo_meta->options.p_tts && philo_meta->options.p_tts < 1000))
		return (1);
	return (0);
}
