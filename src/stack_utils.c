/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:44:21 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/21 17:44:22 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *new_node(int num)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (node == NULL)
        error("malloc");
    node->num = num;
    node->next = NULL;
    return (node);
}

t_stack *last_node(t_stack *stack)
{
    if (stack == NULL)
    {
        error("empty");
        return (NULL);
    }
    while (stack->next)
        stack = stack->next;
    return (stack);
}

t_stack *node_to_stack(t_stack **stack, t_stack *node)
{
    if (stack == NULL)
        error("empty");
    else if(*stack == NULL)
        *stack = node;
    else
    {
        last_node(*stack)->next = node;
        node->next = NULL;
    }
}

int check_sorted(t_stack *stack)
{
    t_stack *tmp;

    while (stack)
    {
        tmp = stack->next;
        while (tmp)
        {
            if (tmp->num < stack->num)
                return (0);
            tmp = tmp->next;
        }
        stack = stack->next;
    }
    return (1);
}

void print_stack(t_stack *stack)
{
    while (stack != NULL)
    {
        printf(" %lld\n", stack->num);
        stack = stack->next;
    }
}