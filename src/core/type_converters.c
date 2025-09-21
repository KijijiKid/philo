/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_converters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:32:53 by mandre            #+#    #+#             */
/*   Updated: 2025/09/21 21:11:15 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int parse_digits_rec(const char *p, int acc)
{
	if (!('0'<= *p && *p <= '9'))
		return acc;
	return parse_digits_rec(p + 1, acc * 10 + (*p - '0'));
}

int ft_atoi(const char *s)
{
	int sign;

	while (*s == ' ' || *s =='\v' || *s == '\t')
		s++;
	sign = 1;
	if (*s == '+' || *s == '-') {
		if (*s == '-') 
			sign = -1;
		s++;
	}
	int value = parse_digits_rec(s, 0);
	return (sign * value);
}