/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:40:55 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/03 04:40:56 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	long	temp_num;
	int		error_flag;
	t_stack	*new_node;

	stack_a = NULL;
	i = 1;
	error_flag = 0;
	while (i < argc)
	{
		if (!is_valid_number_format(argv[i]))
			exit_error(&stack_a, NULL);
		temp_num = ft_atoi_check(argv[i], &error_flag);
		if (error_flag)
			exit_error(&stack_a, NULL);
		new_node = create_node((int)temp_num);
		if (!new_node)
			exit_error(&stack_a, NULL);
		add_node_back(&stack_a, new_node);
		i++;
	}
	if (check_duplicates(stack_a))
		exit_error(&stack_a, NULL);
	return (stack_a);
}
