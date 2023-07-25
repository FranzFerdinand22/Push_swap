
#include "push_swap.h"

void error(char *str)
{
    if (strcmp(str, "input") == 0)
        printf("Error: Wrong input\n");
    else if (strcmp(str, "badnum") == 0)
        {
            printf("Error: Too big/small or incomplete number\n");
            exit(1);
        }
    else if (strcmp(str, "malloc") == 0)
        printf("Error: Wrong memory allocation\n");
    else if (strcmp(str, "empty or dup") == 0)
    {
        printf("Error: Stack is empty or there is duplicate\n");
        exit (1);
    }
    else if (strcmp(str, "empty") == 0)
        printf("Error: Stack is empty\n");
    else
        printf("Error!\n");
}

t_stack *new_node(int num)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (new == NULL)
        error("malloc");
    new->num = num;
    new->next = NULL;
    return (new);
}

t_stack *last_node(t_stack *stack)
{
    if (stack == NULL)
    {
        error("empty");
        return (NULL);
    }
    while(stack->next)
        stack = stack->next;
    return (stack);
}

void node_to_stack(t_stack **stack, t_stack *node)
{
    if (stack == NULL)
        error("empty");
    else if (*stack == NULL)
        *stack = node;
    else
    {
        (last_node(*stack))->next = node;
        node->next = NULL;
    }
}

void print_stack(t_stack *stack)
{
    while (stack != NULL)
    {
        printf(" %lld\n", stack->num);
        stack = stack->next;
    }
}

void print_indexs(t_stack *stack)
{
    while (stack != NULL)
    {
        printf(" %d\n", stack->index);
        stack = stack->next;
    }
}

void free_arr(char **arr)
{
    if (!arr)
        return;

    char **ptr = arr;
    while (*ptr != NULL)
    {
        free(*ptr);
        *ptr = NULL;
        ptr++;
    }
    free(arr);
}

int check_dup(t_stack *stack)
{
    t_stack *tmp;

    while(stack != NULL)
    {
        tmp = stack->next;
        while (tmp != NULL)
        {
            if(tmp->num == stack->num)
                return (1);
            tmp = tmp->next;
        }
        stack = stack->next;
    }
}

void free_stack(t_stack **nodes)
{
    int i;
    t_stack *node;

    i = 0;
    if (!nodes)
        return ;
    while (*nodes)
    {   
        node = (*nodes)->next;
        (*nodes)->num = 0;
        free(*nodes);
        (*nodes) = node;
    }
}