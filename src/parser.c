/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:40:55 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/09 02:18:54 by ehabes           ###   ########.fr       */
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

static void	parse_argument(char *arg, t_stack **stack_a)
{
	char	**numbers;
	int		i;
	int		process_result;

	numbers = ft_split(arg, ' ');
	if (!numbers)
		exit_error(stack_a, NULL);
	i = 0;
	process_result = 1;
	while (numbers[i] != NULL && process_result)
	{
		process_result = process_number_string(numbers[i], stack_a);
		i++;
	}
	free_split_result(numbers);
	if (!process_result)
		exit_error(stack_a, NULL);
}

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			exit_error(&stack_a, NULL);
		parse_argument(argv[i], &stack_a);
		i++;
	}
	if (check_duplicates(stack_a))
		exit_error(&stack_a, NULL);
	return (stack_a);
}
