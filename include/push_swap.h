/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:39:55 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/03 21:01:32 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "../lib/libft/libft.h" // libft
# include "../lib/ft_printf/libftprintf.h" //ft_printf

# include <unistd.h> 
# include <stdlib.h>

/* Represents a node in the stack */
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

/* error_utils.c: Handles errors and exits */
void	exit_error(t_stack **a, t_stack **b);

/* validation_utils.c: Input validation helpers */
int		is_valid_number_format(char *str);
long	ft_atoi_check(const char *str, int *error_flag);

/* duplicate_utils.c: Checks for duplicate values */
int		check_duplicates(t_stack *stack);

/* stack_utils.c: Basic stack manipulation functions */
t_stack	*create_node(int value);
void	add_node_back(t_stack **stack, t_stack *new_node);
void	free_stack(t_stack **stack);
int		get_stack_size(t_stack *stack);

/* parser.c: Parses arguments into stack A */
t_stack	*parse_arguments(int argc, char **argv);

/* operations_swap.c: Swap operations */
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);

/* operations_push.c: Push operations */
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);

/* operations_rotate.c: Rotate operations */
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);

/* operations_reverse_rotate.c: Reverse rotate operations */
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

/* sort_utils.c: Sorting helpers */
int		is_sorted(t_stack *stack);
void	sort_small_stack(t_stack **a, t_stack **b);

/* sorting_algo.c: Main sorting logic */
void	push_swap_algo(t_stack **a, t_stack **b);

/* indexing_utils.c: Assigns sorted indices */
void	assign_indices(t_stack *a);

#endif