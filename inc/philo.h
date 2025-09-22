/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:25:50 by mandre            #+#    #+#             */
/*   Updated: 2025/09/22 18:04:52 by mandre           ###   ########.fr       */
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

/*Error MSG define*/

# define WRONG_INPUT	"You provided wrong amount of input.\n"
# define WRONG_TYPE		"One of the provided options wasn't the right type.\n"
# define EXPECTED_INPUT	"Expected Input:\n./philo number_of_philosophers(int) time_to_die time_to_eat(double) time_to_sleep(double) [number_of_times_each_philosopher_must_eat](int)\n"

/*Meta Struct*/

typedef struct s_meta
{
	int			philosophers_count;
	double		time_to_die;
	double		time_to_eat;
	double		time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
	pthread_t	*thread;
}   t_meta;


/*Function Prototypes*/
int		ft_atoi(const char *s);
double	str_to_double(char *s);
void	write_error(int status);
int		input_parsing(int argc, char **argv, t_meta *philo_meta);
int		create_threads(t_meta *philo_meta);


#endif