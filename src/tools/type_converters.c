/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_converters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:41:14 by mandre            #+#    #+#             */
/*   Updated: 2025/09/30 11:38:51 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:03:18 by mandre            #+#    #+#             */
/*   Updated: 2025/03/22 13:28:39 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	multiply;

	i = 0;
	multiply = 1;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			multiply = -1;
		i++;
	}
	number = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	number *= multiply;
	return (number);
}

static size_t	get_length(long n)
{
	long	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i = 1;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_ltoa(long n)
{
	char	*array;
	long	i;
	long	num;

	num = ((long)n);
	i = get_length(n);
	array = (char *)malloc(sizeof(char) * (i + 1));
	if (!array)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		array[0] = '-';
	}
	array[i] = '\0';
	while (0 <= i && num != 0)
	{
		i--;
		array[i] = (num % 10) + '0';
		num /= 10;
	}
	if (0 == n)
		array[0] = '0';
	return (array);
}
