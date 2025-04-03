/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:41:31 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/03 04:41:32 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_digit_or_sign(char c, int is_first_char)
{
	if (ft_isdigit(c))
		return (1);
	if (is_first_char && (c == '+' || c == '-'))
		return (1);
	return (0);
}

int	is_valid_number_format(char *str)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (!is_digit_or_sign(str[i], i == 0))
			return (0);
		if (ft_isdigit(str[i]))
			has_digit = 1;
		if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
			return (0);
		i++;
	}
	if (!has_digit || ((str[0] == '+' || str[0] == '-') && str[1] == '\0'))
		return (0);
	return (1);
}

static long	perform_conversion(const char *str, int sign, int *error_flag)
{
	long	result;
	int		digit;

	result = 0;
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		if (sign == 1 && result > (INT_MAX - digit) / 10)
			*error_flag = 1;
		else if (sign == -1 && result > ((long)INT_MAX + 1 - digit) / 10)
			*error_flag = 1;
		if (*error_flag)
			return (0);
		result = result * 10 + digit;
		str++;
	}
	return (result);
}

long	ft_atoi_check(const char *str, int *error_flag)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	*error_flag = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = perform_conversion(str, sign, error_flag);
	if (*error_flag)
		return (0);
	return (result * sign);
}
