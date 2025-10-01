/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:25:50 by mandre            #+#    #+#             */
/*   Updated: 2025/10/01 16:43:45 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*Common Libaries*/
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

//Time magic number UTC to ETC (hours
# define TIME_ZONE_OFFSET 2

//Error MSG define
# define W_INPUT "Wrong Input\n"
# define E_INPUT "Expected: NUM_PHILO(1-200) ttd tte tts [tepme]\n"
# define T_C_FAILED "Thread creation failed\n"
# define T_J_FAILED "Thread joining/termination failed\n"
# define I_MTX_FAILED "Initalization of Mutexes failed\n"
# define D_MTX_FAILED "Destroying Mutexes failed\n"
# define GTOD_FAILED "gettimeofday() failed\n"

/// @brief 
/// p_num Number of philosophers
/// p_ttd Time to die
/// p_tte Time to eat
/// p_tts Time to sleep
/// p_mec Number of times each philo must have eaten
typedef struct s_options
{
	unsigned int	p_num;
	size_t			p_ttd;
	size_t			p_tte;
	size_t			p_tts;
	unsigned int	p_mec;
	size_t			start_time;
}	t_options;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*sync_lock_ptr;
	bool			*sync_flag_ptr;
}	t_philo;

typedef struct s_meta
{
	t_options	options;
	pthread_mutex_t	sync_lock;
	bool			sync_flag;
	t_philo		philo[200];
}	t_meta;

typedef enum e_status
{
	WRONG_INPUT = 1,
	THREAD_CREATION_FAILED = 2,
	THREAD_JOIN_FAILED = 3,
	INIT_MUTEX_FAILED = 4,
	DSTRY_MUTEX_FAILED = 5,
	GET_TIME_FAILED = 6
}	t_status;

typedef enum e_action
{
	SLEEP = 1,
	EAT = 2,
	THINK = 3,
	T_FORK = 4
}	t_action;

//Core
void	*routine(void *data);
int		init_forks(t_meta *meta);
void	philo_hold(t_philo *philo);
void	philo_start(t_meta *meta);

//Tools
int		ft_atoi(const char *str);
size_t	get_curr_time(void);
// char	*formated_time(void);
int		input_parsing(int argc, char **argv, t_meta *philo_meta);
// int		write_action(t_philo *philo, t_action action);
void 	ft_usleep(size_t ms);
char	*ft_ltoa(long n);

//Error
int		throw_error(t_status status);

#endif