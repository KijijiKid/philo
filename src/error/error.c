/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:47:10 by mandre            #+#    #+#             */
/*   Updated: 2025/09/28 15:30:32 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	write_input(char *msg1, char *msg2)
{
	write(2, msg1, ft_strlen(msg1));
	if (msg2)
		write(2, msg2, ft_strlen(msg2));
}

int	throw_error(t_status status)
{
	if (status == WRONG_INPUT)
		write_input(W_INPUT, E_INPUT);
	else if (status == THREAD_CREATION_FAILED)
		write_input(T_C_FAILED, NULL);
	else if (status == THREAD_JOIN_FAILED)
		write_input(T_J_FAILED, NULL);
	else if (status == INIT_MUTEX_FAILED)
		write_input(I_MTX_FAILED, NULL);
	else if (status == DSTRY_MUTEX_FAILED)
		write_input(D_MTX_FAILED, NULL);
	return (status);
}
