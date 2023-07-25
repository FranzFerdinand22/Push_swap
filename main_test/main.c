
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_A;

    stack_A = check_input(argc, argv);
    print_stack(stack_A);
    if (!stack_A || check_dup(stack_A) == 1)
    {
        free_stack(&stack_A);
        error("empty or dup");
    }
    if (check_sorted(stack_A) != 1)
        sort(&stack_A);

    return (0);
}