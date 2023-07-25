
#include "push_swap.h"

void    ss(t_stack **stack_A, t_stack **stack_B, int i)
{
    sa(stack_A, i);
    sb(stack_B, i);
    if (i == 1)
        write(1, "ss\n", 3);
}

void    rr(t_stack **stack_A, t_stack **stack_B, int i)
{
    ra(stack_A, i);
    rb(stack_B, i);
    if (i == 1)
        write(1, "rr\n", 3);
}

void    rrr(t_stack **stack_A, t_stack **stack_B, int i)
{
    rra(stack_A, i);
    rrb(stack_B, i);
    if (i == 1)
        write(1, "rrr\n", 3);
}