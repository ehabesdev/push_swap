/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 05:40:39 by ehabes            #+#    #+#             */
/*   Updated: 2025/04/20 23:13:21 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "../lib/get_next_line/get_next_line.h"
# include "../../lib/libft/libft.h"
# include "../../lib/ft_printf/libftprintf.h"

# include <unistd.h> 
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

int		execute_operation(char *line, t_stack **a, t_stack **b);

void	exit_error(t_stack **a, t_stack **b);

int		is_valid_number_format(char *str);
long	ft_atoi_check(const char *str, int *error_flag);

int		check_duplicates(t_stack *stack);

t_stack	*create_node(int value);
void	add_node_back(t_stack **stack, t_stack *new_node);
void	free_stack(t_stack **stack);
int		get_stack_size(t_stack *stack);

t_stack	*parse_arguments(int argc, char **argv);

void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);

void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);

void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);

void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

int		is_sorted(t_stack *stack);
void	sort_small_stack(t_stack **a, t_stack **b);

void	push_swap_algo(t_stack **a, t_stack **b);
int		find_index_position(t_stack *stack, int target_index);

void	assign_indices(t_stack *a);

#endif