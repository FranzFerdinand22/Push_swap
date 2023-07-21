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

//special atoi for push swap
int ft_atoi_ps(const char *str)
{
    int minus;
    int res;

    res = 0;
    minus = 1;
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f' || *str == '\v' || *str == '\r')
        str++;
    if(*str == '+' || *str == '-')
    {
        if (*str == '-')
            minus = -1;
        str++;
    }
    while (*str)
    {
        if (*str < '0' || *str > '9')
            error("badnum");
        res = res * 10 + (*str - '0');
        str++;
    }
    if ((res * minus) > 2147483647 || (res * minus) < -2147483648)
		error("badnum");
    return (res * minus);
}

//split string to single input->return stack
t_stack *single_input(char **argv)
{
    t_stack *stack_A;
    char **arr;
    int i;
    int j;

    i = 0;
    j = 0;
    stack_A = NULL;
    arr = ft_split(argv[1], ' ');
    while (arr[i])
    {
        j = ft_atoi_ps(arr[i]);
        node_to_stack(&stack_A, new_node(j));
        i++;
    }
    free_arr(arr);
    return (stack_A);
}

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
            node_to_stack(&stack_A, new_node(j));
            i++;
        }
    }
    return (stack_A);
}
