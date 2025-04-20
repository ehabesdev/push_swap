/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:40:13 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/20 23:34:08 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	exit_error(t_stack **a, t_stack **b)
{
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}
