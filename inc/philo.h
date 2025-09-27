/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:25:50 by mandre            #+#    #+#             */
/*   Updated: 2025/09/27 20:42:52 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*Common Libaries*/
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h> // get_time_of_day
# include <pthread.h> // Thread functions
# include <stdbool.h> //Boolean

# define TIME_ZONE_OFFSET 2

/// @brief 
/// p_num Number of philosophers
/// p_ttd Time to die
/// p_tte Time to eat
/// p_tts Time to sleep
/// p_mec Number of times each philo must have eaten
typedef struct s_options
{
	unsigned int	p_num;
	unsigned int	p_ttd;
	unsigned int	p_tte;
	unsigned int	p_tts;
	unsigned int	p_mec;
}	t_options;

typedef struct s_philo
{
	unsigned int	id;
	
}	t_philo;

typedef struct s_meta
{
	t_philo			philo[200];
	pthread_mutex_t	write_lock; //Whenever printf or write gets called
	t_options		option;
}	t_meta;


//Tools
int		ft_atoi(const char *str);
size_t	get_curr_time(void);
char	*formated_time(void);

#endif