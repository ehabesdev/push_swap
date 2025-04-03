/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:40:27 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/03 04:40:28 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node_to_push;

	if (!src || !*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	node_to_push->next = *dest;
	*dest = node_to_push;
}

void	pa(t_stack **a, t_stack **b, int print)
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, int print)
{
	push(b, a);
	if (print)
		ft_printf("pb\n");
}
