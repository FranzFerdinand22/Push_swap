

#include "push_swap.h"

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

int stack_size(t_stack *stack)
{
    int i;

    i = 0;
    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}