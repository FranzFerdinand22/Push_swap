/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:01:16 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/24 20:20:21 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push a: take the first element at the top of b and 
// put it at the top of a. Do nothing if b is empty.
void	pa(t_stack **stack_A, t_stack **stack_B, int i)
{
	t_stack		*tmp;

	tmp = (*stack_A);
	if (!(*stack_B))
		return ;
	(*stack_A) = (*stack_B);
	(*stack_B) = (*stack_B)->next;
	(*stack_A)->next = tmp;
	if (i == 0)
		write(1, "pa\n", 3);
}

// swap a : swap the first 2 elements at the top of stack a. 
// Do nothing if there is only one or no elements.
void	sa(t_stack **stack_A, int i)
{
	t_stack		*tmp;

	tmp = *stack_A;
	if (!(*stack_A) || !(*stack_A)->next)
		return ;
	(*stack_A) = (*stack_A)->next;
	tmp->next = (*stack_A)->next;
	(*stack_A)->next = tmp;
	if (i == 0)
		write(1, "sa\n", 3);
}

// ra rotate a: shift up all elements of stack a by 1. 
// The first element becomes the last one.
void	ra(t_stack **stack_A, int i)
{
	t_stack		*tmp;

	tmp = *stack_A;
	if (!stack_A || !(*stack_A)->next)
		return ;
	(*stack_A) = last_node(*stack_A);
	(*stack_A)->next = tmp;
	*stack_A = tmp->next;
	tmp->next = NULL;
	if (i == 0)
		write(1, "ra\n", 3);
}

// reverse rotate a: shift down all elements of stack a by 1. 
// The last element becomes the first one.
void	rra(t_stack **stack_A, int i)
{
	int		j;
	t_stack	*tmp;

	j = 0;
	tmp = *stack_A;
	if (!stack_A || !(*stack_A)->next)
		return ;
	while ((*stack_A)->next)
	{
		*stack_A = (*stack_A)->next;
		j++;
	}
	(*stack_A)->next = tmp;
	while (j > 1)
	{
		tmp = tmp->next;
		j--;
	}
	tmp->next = NULL;
	if (i == 0)
		write(1, "rra\n", 4);
}
