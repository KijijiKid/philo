/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:25:50 by mandre            #+#    #+#             */
/*   Updated: 2025/09/24 19:36:53 by mandre           ###   ########.fr       */
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

/*Error MSG define*/

# define WRONG_INPUT	"You provided wrong amount of input.\n"
# define WRONG_TYPE		"One of the provided options wasn't the right type.\n"
# define EXPECTED_INPUT	"Expected Input:\n./philo number_of_philosophers(int) time_to_die time_to_eat(double) time_to_sleep(double) [number_of_times_each_philosopher_must_eat](int)\n"
# define TIME_ERROR		"gettimeofday() failed\n"
# define MUTEX_ERROR	"Initialization of mutex failed\n"

/*Meta Structs*/

typedef struct	philo_s
{
	pthread_t		thread;
	size_t			id; // Philo ID for printing MSG
	double			time_last_meal;
	size_t			number_of_meals; //Times the philo already had a meal
	bool			*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*dead_lock;
}	philo_t;

typedef struct s_meta
{
	int				philosophers_count;
	bool			dead;
	double			time_to_die;
	double			time_to_eat;
	double			time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	total_forks[200];
	pthread_t		msg_thread; // For displaying msg's on the board
	pthread_mutex_t	msg_mutex;
	philo_t			philo[200];
}   t_meta;


/*Function Prototypes*/
int		ft_atoi(const char *s);
double	str_to_double(char *s);
void	write_error(int status);
int		input_parsing(int argc, char **argv, t_meta *philo_meta);
int		create_threads(t_meta *philo_meta);
int		init_structs(t_meta *philo_meta);
int		clean_all(t_meta *philo_meta);
void	ft_usleep(size_t ms);
void	*routine(philo_t *philo);
void	init_forks(t_meta *philo_meta);
void	assign_forks(t_meta *philo_meta, philo_t *philo);
void	destroy_forks(t_meta *philo_meta);
void	*monitor_init(void);

#endif