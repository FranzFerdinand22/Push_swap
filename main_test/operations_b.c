
#include "push_swap.h"

// push b: take the first element at the top of a and 
// put it at the top of b. Do nothing if b is empty.
void    pb(t_stack **stack_A, t_stack **stack_B, int i)
{
    t_stack *tmp;

    tmp = NULL;
    if (!*stack_A)
        return ;
    tmp = *stack_B;
    *stack_B = *stack_A;
    *stack_A = (*stack_A)->next;
    (*stack_B)->next = tmp;
    if (i == 0)
        write(1, "pb\n", 3);
}

// swap b : swap the first 2 elements at the top of stack b. 
// Do nothing if there is only one or no elements.
void    sb(t_stack **stack_B, int i)
{
    t_stack *tmp;

    tmp = NULL;
    if (!stack_B || !(*stack_B)->next)
        return ;
    tmp = *stack_B;
    *stack_B = (*stack_B)->next;
    tmp->next = (*stack_B)->next;
    (*stack_B)->next = tmp;
    if (i == 0)
        write(1, "sb\n", 3);
}


// ra rotate b: shift up all elements of stack b by 1. 
// The first element becomes the last one.
void    rb(t_stack **stack_B, int i)
{
    t_stack *tmp;

    tmp = NULL;
    if (!stack_B || !(*stack_B)->next)
        return ;
    tmp = *stack_B;
    *stack_B = last_node(*stack_B);
    (*stack_B)->next = tmp;
    *stack_B = tmp->next;
    tmp->next = NULL;
    if (i == 0)
        write(1, "rb\n", 3);
}

// reverse rotate b: shift down all elements of stack b by 1. 
// The last element becomes the first one.
void    rrb(t_stack **stack_B, int i)
{
    t_stack *tmp;
    int j;

    j = 0;
    tmp = NULL;
    if (!stack_B || !(*stack_B)->next)
        return ;
    tmp = *stack_B;
    while ((*stack_B)->next)
    {
        *stack_B = (*stack_B)->next;
        j++;
    }
    (*stack_B)->next = tmp;
    while (j > 1)
    {
        tmp = tmp->next;
        j--;
    }
    tmp->next = NULL;
    if (i == 0)
        write(1, "rrb\n", 4);
}
