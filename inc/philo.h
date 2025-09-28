/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:25:50 by mandre            #+#    #+#             */
/*   Updated: 2025/09/28 13:19:15 by mandre           ###   ########.fr       */
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

//Time magic number UTC to ETC (hours
# define TIME_ZONE_OFFSET 2

//Error MSG define
# define W_INPUT "Wrong Input\n"
# define E_INPUT "Expected: NUM_PHILO(1-200) ttd tte tts [tepme]\n"

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

typedef enum e_status
{
	WRONG_INPUT = 1,
	
}	t_status;

//Core


//Tools
int		ft_atoi(const char *str);
size_t	get_curr_time(void);
char	*formated_time(void);
int		input_parsing(int argc, char **argv, t_meta *philo_meta);

//Error
int		throw_error(t_status status);

#endif