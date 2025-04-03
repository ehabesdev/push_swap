/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:40:23 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/03 04:40:24 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;
	int	swapped;

	if (!arr || size < 2)
		return ;
	i = -1;
	while (++i < size - 1)
	{
		swapped = 0;
		j = -1;
		while (++j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
		}
		if (!swapped)
			break ;
	}
}

static int	*copy_stack_to_array(t_stack *a, int size)
{
	int		*arr;
	int		i;
	t_stack	*current;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	current = a;
	i = 0;
	while (current && i < size)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	return (arr);
}

static void	set_indices_from_array(t_stack *a, int *sorted_arr, int size)
{
	t_stack	*current;
	int		i;

	current = a;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == sorted_arr[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	assign_indices(t_stack *a)
{
	int		*arr;
	int		size;

	size = get_stack_size(a);
	if (size <= 1)
		return ;
	arr = copy_stack_to_array(a, size);
	if (!arr)
		exit_error(NULL, NULL);
	bubble_sort(arr, size);
	set_indices_from_array(a, arr, size);
	free(arr);
}
