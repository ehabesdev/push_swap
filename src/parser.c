/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:40:55 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/04 15:32:55 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	free_split_result(char **split_result)
{
	int	i;

	if (!split_result)
		return ;
	i = 0;
	while (split_result[i])
	{
		free(split_result[i]);
		i++;
	}
	free(split_result);
}

static int	process_number_string(char *num_str, t_stack **stack_a)
{
	long	temp_num;
	int		error_flag;
	t_stack	*new_node;

	error_flag = 0;
	new_node = NULL;
	if (!is_valid_number_format(num_str))
		return (0);
	temp_num = ft_atoi_check(num_str, &error_flag);
	if (error_flag)
		return (0);
	new_node = create_node((int)temp_num);
	if (!new_node)
		return (0);
	add_node_back(stack_a, new_node);
	return (1);
}

static t_stack	*parse_single_string_arg(char *arg_str)
{
	t_stack	*stack_a;
	char	**numbers;
	int		i;
	int		process_result;

	stack_a = NULL;
	numbers = NULL;
	process_result = 1;
	numbers = ft_split(arg_str, ' ');
	if (!numbers)
		exit_error(NULL, NULL);
	i = 0;
	while (numbers[i] != NULL && process_result)
	{
		if (numbers[i][0] == '\0')
			i++;
		process_result = process_number_string(numbers[i], &stack_a);
		i++;
	}
	free_split_result(numbers);
	if (!process_result || stack_a == NULL)
		exit_error(&stack_a, NULL);
	return (stack_a);
}

static t_stack	*parse_multiple_args(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		process_status;

	stack_a = NULL;
	i = 1;
	process_status = 1;
	while (i < argc && process_status)
	{
		process_status = process_number_string(argv[i], &stack_a);
		i++;
	}
	if (!process_status)
		exit_error(&stack_a, NULL);
	return (stack_a);
}

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc == 2)
		stack_a = parse_single_string_arg(argv[1]);
	else if (argc > 2)
		stack_a = parse_multiple_args(argc, argv);
	if (check_duplicates(stack_a))
		exit_error(&stack_a, NULL);
	return (stack_a);
}
