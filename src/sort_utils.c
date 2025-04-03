/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:41:06 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/03 04:41:10 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	sort_three(t_stack **a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*a)->value;
	middle = (*a)->next->value;
	bottom = (*a)->next->next->value;
	if (top > middle && middle < bottom && top > bottom)
		ra(a, 1);
	else if (top > middle && middle > bottom)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (top > middle && middle < bottom && top < bottom)
		sa(a, 1);
	else if (top < middle && middle > bottom && top < bottom)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(a, 1);
}

void	sort_small_stack(t_stack **a, t_stack **b)
{
	int	size;

	(void)b;
	size = get_stack_size(*a);
	if (size == 2 && !is_sorted(*a))
		sa(a, 1);
	else if (size == 3)
		sort_three(a);
}
