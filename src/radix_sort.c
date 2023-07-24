/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:24:38 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/24 20:47:36 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bitwise_part(t_stack **stack_A, t_stack **stack_B, int max_bits)
{
	int	i;
	int	j;
	int	current_size;
	int	num;

	i = 0;
	j = 0;
	while (i < max_bits)
	{
		j = 0;
		current_size = stack_size(*stack_A);
		while (j < current_size)
		{
			num = (*stack_A)->index;
			if ((num >> i) & 1 == 1)
				ra(stack_A, 0);
			else
				pb(stack_A, stack_B, 0);
			j++;
		}
		while (*stack_B != NULL)
			pa(stack_A, stack_B, 0);
		i++;
	}
}

void	radix_sort(t_stack **stack_A, t_stack **stack_B)
{
	int	size;
	int	max_num;
	int	max_bits;
	int	current_size;
	int	num;

	size = stack_size(*stack_A);
	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	bitwise_part(stack_A, stack_B, max_bits);
}
