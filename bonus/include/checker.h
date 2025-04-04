/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 05:40:39 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/04 13:28:27 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../include/push_swap.h" // PS
# include "../lib/get_next_line/get_next_line.h" // GNL

/* checker_utils.c: Parses and executes one operation line from stdin */
int	execute_operation(char *line, t_stack **a, t_stack **b);

#endif