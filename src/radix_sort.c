/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:24:38 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/24 17:24:42 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void radix_sort(t_stack **stack_A, t_stack **stack_B)
{
    int size = stack_size(*stack_A);
    int max_num = size - 1;
    int max_bits = 0;

    while ((max_num >> max_bits) != 0)
        max_bits++;

    for (int i = 0; i < max_bits; ++i)
    {
        int current_size = stack_size(*stack_A);

        for (int j = 0; j < current_size; ++j)
        {
            int num = (*stack_A)->index;

            if ((num >> i) & 1 == 1)
                ra(stack_A, 0);
            else
                pb(stack_A, stack_B, 0);
        }

        while (*stack_B != NULL)
            pa(stack_A, stack_B, 0);
    }
}
