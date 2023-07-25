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

t_stack *single_input(char **argv)
{
    t_stack *stack;
    char **arr;
    int i;
    int j;

    i = 0;
    j = 0;
    stack = NULL;
    arr = ft_split(argv[1], ' ');
    while (arr[i])
    {
        j = ft_atoi_ps(arr[i]);
        node_to_stack(&stack, new_node(j));
        i++;
    }
    free_arr(arr);
    return (stack);
}

//check the input->make stack from input->returns stack
t_stack *check_input(int argc, char **argv)
{
    t_stack *stack;
    int i;
    int j;

    i = 1;
    j = 0;
    stack = NULL;
    if (argc < 2)
        error("input");
    else if (argc == 2)
        //printf("Stdin: One nuber or string of numbers\n");
        stack = single_input(argv);
    else
    {   //printf("Stdin: More than one nuber or string\n");
        while (i < argc)
        {
            j = ft_atoi_ps(argv[i]);
            node_to_stack(&stack, new_node(j));
            i++;
        }
    }
    return (stack);
}