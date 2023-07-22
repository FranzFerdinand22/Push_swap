/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:19:06 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/21 15:19:09 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_A;

    stack_A = stdin_to_stack(argc, argv);
    print_stack(stack_A);
    if (!stack_A || check_dup(stack_A) == 1)
    {
        free_stack(&stack_A);
        error("empty or dup");
    }

    return (0);
}
