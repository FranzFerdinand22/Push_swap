/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:03:33 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/24 20:21:53 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa and sb at the same time
void	ss(t_stack **stack_A, t_stack **stack_B, int i)
{
	sa(stack_A, i);
	sb(stack_B, i);
	if (i == 1)
		write(1, "ss\n", 3);
}

// ra and rb at the same time
void	rr(t_stack **stack_A, t_stack **stack_B, int i)
{
	ra(stack_A, i);
	rb(stack_B, i);
	if (i == 1)
		write(1, "rr\n", 3);
}

// rra and rrb at the same time
void	rrr(t_stack **stack_A, t_stack **stack_B, int i)
{
	rra(stack_A, i);
	rrb(stack_B, i);
	if (i == 1)
		write(1, "rrr\n", 3);
}
