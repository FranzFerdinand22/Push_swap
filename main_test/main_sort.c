
#include "push_swap.h"

t_stack *sort_B(t_stack **stack_A)
{
    t_stack *stack_B;

    stack_B = NULL;

    if (stack_size(*stack_A) > 3 && !check_sorted(*stack_A))
        pb(stack_A, &stack_B, 0);
    if (stack_size(*stack_A) > 3 && !check_sorted(*stack_A))
        pb(stack_A, &stack_B, 0);
    if (!check_sorted(stack_B))
        sb(&stack_B, 0);
    return(stack_B);
}

void sort(t_stack **stack_A)
{
    t_stack *stack_B;
    int len = stack_size(*stack_A);

    stack_B = NULL;
    if (stack_size(*stack_A) == 2)
        sa(stack_A, 0);
    else
    {   
        index_num(*stack_A);
        printf("Stack_indexes A: \n");
        print_indexs(*stack_A);
    }
}