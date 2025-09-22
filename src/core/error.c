/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:27:28 by mandre            #+#    #+#             */
/*   Updated: 2025/09/22 15:58:57 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_error(int status)
{
	if (status == 1)
		printf("%s%s", WRONG_INPUT, EXPECTED_INPUT);
	else if (status == 2)
		printf("%s%s", WRONG_TYPE, EXPECTED_INPUT);
	exit (status);
}