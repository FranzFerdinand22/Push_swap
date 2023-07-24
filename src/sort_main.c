/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:45:11 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/24 20:29:47 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// take stack A -> make indexes -> sort indexes with radix
void	sort(t_stack **stack_A)
{
	int		len;
	t_stack	*stack_b;

	stack_b = NULL;
	len = stack_size(*stack_A);
	if (stack_size(*stack_A) == 2)
		sa(stack_A, 0);
	else
	{
		index_nbrs(*stack_A);
		printf("Index:\n");
		print_indexs(*stack_A);
		radix_sort(stack_A, &stack_b);
		printf("Index:\n");
		print_indexs(*stack_A);
	}
}
