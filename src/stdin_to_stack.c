/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:23:12 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/21 15:23:13 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//check the input->make stack from input->returns stack
t_stack *stdin_to_stack(int argc, char **argv)
{
    t_stack *stack_A;
    int i;
    int j;

    i = 1;
    j = 0;
    stack_A = NULL;
    if (argc < 2)
        error("stdin");
    else if (argc == 2)
        stack_A = single_input(argv);
    else
    {
        while (i < argc)
        {
            j = ft_atoi_ps(argv[i]);
            node_to_stac(&stack_A, new_node(j));
            i++;
        }
    }
    return (stack_A);
}
