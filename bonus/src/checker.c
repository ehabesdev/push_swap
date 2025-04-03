/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 05:32:55 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/03 19:51:30 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static void	read_and_execute_operations(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		execute_operation(line, a, b);
		free(line);
		line = get_next_line(0);
	}
}

static void	check_and_print_result(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && get_stack_size(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = parse_arguments(argc, argv);
	stack_b = NULL;
	read_and_execute_operations(&stack_a, &stack_b);
	check_and_print_result(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
