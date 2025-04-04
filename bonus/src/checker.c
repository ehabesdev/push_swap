/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 05:32:55 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/04 13:44:40 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static int	read_and_execute_operations(t_stack **a, t_stack **b)
{
	char	*line;
	int		result;

	line = get_next_line(0);
	while (line != NULL)
	{
		result = execute_operation(line, a, b);
		free(line);
		if (result == 0)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		line = get_next_line(0);
	}
	return (1);
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
	int		read_result;

	if (argc < 2)
		return (0);
	stack_a = parse_arguments(argc, argv);
	stack_b = NULL;
	read_result = read_and_execute_operations(&stack_a, &stack_b);
	get_next_line(-1);
	if (read_result == 1)
		check_and_print_result(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (read_result == 0)
		return (1);
	return (0);
}
