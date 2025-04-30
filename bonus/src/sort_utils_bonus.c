/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:41:06 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/20 23:34:42 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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

static void	bring_to_top_a(t_stack **a, int target_index)
{
	int	position;
	int	size;
	int	moves;

	size = get_stack_size(*a);
	if (size <= 1)
		return ;
	position = find_index_position(*a, target_index);
	if (position == -1 || position == 0)
		return ;
	if (position <= size / 2)
	{
		while (position-- > 0)
			ra(a, 1);
	}
	else
	{
		moves = size - position;
		while (moves-- > 0)
			rra(a, 1);
	}
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

static void	sort_five(t_stack **a, t_stack **b, int size)
{
	if (is_sorted(*a))
		return ;
	bring_to_top_a(a, 0);
	if (is_sorted(*a))
		return ;
	pb(a, b, 1);
	if (size == 5)
	{
		bring_to_top_a(a, 1);
		if (is_sorted(*a))
		{
			pa(a, b, 1);
			return ;
		}
		pb(a, b, 1);
	}
	sort_three(a);
	if (*b && (*b)->next && (*b)->index < (*b)->next->index)
		sb(b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
}

void	sort_small_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = get_stack_size(*a);
	if (size == 2 && !is_sorted(*a))
		sa(a, 1);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b, size);
}
