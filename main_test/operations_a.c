
#include "push_swap.h"

// push a: take the first element at the top of b and 
// put it at the top of a. Do nothing if b is empty.
void    pa(t_stack **stack_A, t_stack **stack_B, int i)
{
    t_stack *tmp;

    tmp = NULL;
    if (!*stack_B)
        return ;
    tmp = *stack_A;
    *stack_A = *stack_B;
    *stack_B = (*stack_B)->next;
    (*stack_A)->next = tmp;
    if (i == 0)
        write(1, "pa\n", 3);
}

// swap a : swap the first 2 elements at the top of stack a. 
// Do nothing if there is only one or no elements.
void    sa(t_stack **stack_A, int i)
{
    t_stack *tmp;

    tmp = NULL;
    if (!stack_A || !(*stack_A)->next)
        return ;
    tmp = *stack_A;
    *stack_A = (*stack_A)->next;
    tmp->next = (*stack_A)->next;
    (*stack_A)->next = tmp;
    if (i == 0)
        write(1, "sa\n", 3);
}


// ra rotate a: shift up all elements of stack a by 1. 
// The first element becomes the last one.
void    ra(t_stack **stack_A, int i)
{
    t_stack *tmp;

    tmp = NULL;
    if (!stack_A || !(*stack_A)->next)
        return ;
    tmp = *stack_A;
    *stack_A = last_node(*stack_A);
    (*stack_A)->next = tmp;
    *stack_A = tmp->next;
    tmp->next = NULL;
    if (i == 0)
        write(1, "ra\n", 3);
}

// reverse rotate a: shift down all elements of stack a by 1. 
// The last element becomes the first one.
void    rra(t_stack **stack_A, int i)
{
    t_stack *tmp;
    int j;

    j = 0;
    tmp = NULL;
    if (!stack_A || !(*stack_A)->next)
        return ;
    tmp = *stack_A;
    while ((*stack_A)->next)
    {
        *stack_A = (*stack_A)->next;
        j++;
    }
    (*stack_A)->next = tmp;
    while (j > 1)
    {
        tmp = tmp->next;
        j--;
    }
    tmp->next = NULL;
    if (i == 0)
        write(1, "rra\n", 4);
}