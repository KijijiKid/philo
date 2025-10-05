/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:25:50 by mandre            #+#    #+#             */
/*   Updated: 2025/10/05 20:02:30 by mandre           ###   ########.fr       */
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
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

//Time magic number UTC to ETC (hours
# define TIME_ZONE_OFFSET 2

//Error MSG define
# define W_INPUT "Wrong Input\n"
# define E_INPUT "Expected: NUM_PHILO(1-200) ttd tte tts [tepme]\n"
# define T_C_FAILED "Thread creation failed\n"
# define T_J_FAILED "Thread joining/termination failed\n"
# define I_SEM_FAILED "Initalization of Semaphore failed\n"
# define D_SEM_FAILED "Destroying Semaphore failed\n"
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
	size_t			*start_time;
}	t_options;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned int	id;
	sem_t			*alive_lock;
	bool			alive;
	sem_t			*meal_time_lock;
	size_t			last_meal;
	sem_t			*meal_count_lock;
	unsigned int	meal_count;
	t_options		options;
	sem_t			*sync_lock_ptr;
	bool			*sync_flag_ptr;
	sem_t			*write_lock_ptr;
	sem_t			*run_lock_ptr;
	bool			*run_flag_ptr;
}	t_philo;

typedef struct s_meta
{
	t_options			options;
	t_philo				philo[200];
	sem_t				*forks;
	sem_t				*sync_lock;
	bool				sync_flag;
	sem_t				*write_lock;
	sem_t				*run_lock;
	bool				run_flag;
	size_t				start_time;
}	t_meta;

typedef enum e_status
{
	WRONG_INPUT = 1,
	THREAD_CREATION_FAILED = 2,
	THREAD_JOIN_FAILED = 3,
	SEM_CREATION = 4,
	SEM_CLOSE_FAILED = 5,
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
void		*routine(void *data);
int			init_threads(t_meta *meta);
void		philo_hold(t_philo *philo);
void		philo_start(t_meta *meta);
int			init_monitor(t_meta *meta);
int			clean_total_forks(t_meta *meta);
int			clean_res(t_meta *meta);
void		set_time_count(t_philo *philo);
bool		is_alive(t_philo *philo);
void		set_first_meal_time(t_philo *philo);

//Tools
int			ft_atoi(const char *str);
size_t		get_curr_time(void);
int			input_parsing(int argc, char **argv, t_meta *philo_meta);
int			write_action(t_philo *philo, t_action action, bool visible);
void		ft_usleep(size_t ms);
char		*ft_ltoa(long n);
int			init_philo(t_meta *meta, t_philo *philo, unsigned int id);
void		init_meta(t_meta *meta);
char	*set_local_sem_name(const char *str, unsigned int id);

//Error
int		throw_error(t_status status);

#endif