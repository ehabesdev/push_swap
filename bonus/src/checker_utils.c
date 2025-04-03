/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:50:17 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/03 19:50:30 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static int	check_swap_push_ops(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a, 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(a, b, 0);
	else
		return (0);
	return (1);
}

static int	check_rotate_ops(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b, 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b, 0);
	else
		return (0);
	return (1);
}

static int	check_reverse_rotate_ops(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

void	execute_operation(char *line, t_stack **a, t_stack **b)
{
	if (!line || line[0] == '\0' || (line[0] == '\n' && line[1] == '\0'))
		return ;
	if (check_swap_push_ops(line, a, b))
		return ;
	if (check_rotate_ops(line, a, b))
		return ;
	if (check_reverse_rotate_ops(line, a, b))
		return ;
	exit_error(a, b);
}
