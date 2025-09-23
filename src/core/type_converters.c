/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_converters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:32:53 by mandre            #+#    #+#             */
/*   Updated: 2025/09/23 18:00:32 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static int	ft_strlen(char *s)
// {
// 	int i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

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

double	str_to_double(char *s)
{
	int			i;
	int			multiplier;
	int			whole_num;
	double		decimal;
	
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\v')
		i++;
	multiplier = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			multiplier = -1;
		i++;
	}
	whole_num = 0;
	while ('0' <= s[i] && s[i] <= '9')
	{
		whole_num *= 10;
		whole_num += s[i] - '0';
		i++;
	}
	if (s[i] == '.')
			i++;
	decimal = 0;
	while ('0' <= s[i + 1] && s[i + 1] <= '9')
		i++;
	while ('0' <= s[i] && s[i] <= '9')
	{
		decimal += (s[i]) - '0';
		decimal /= 10;
		i--;
	}
	return ((decimal + whole_num) * multiplier);
}
