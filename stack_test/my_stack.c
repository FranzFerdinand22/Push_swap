/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_Stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:35:06 by fptacek           #+#    #+#             */
/*   Updated: 2023/06/29 17:35:07 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _node
{
    int value;
    struct _node *next;
} Node;

typedef struct _stack
{
    Node *head;
    Node *tail;
} Stack;

void create_stack(Stack *stack);
bool is_empty(Stack *stack);
void push(Stack *stack, int value);
void peek(Stack *stack);
int stack_size(Stack *stack);
Stack *swap(Stack *stack);
bool push_over(Stack *stack_A, Stack *stack_B);
bool rotate(Stack *stack);
bool revers_rotate(Stack *stack);
void print_stack(Stack *stack);


/*int main()
{
    Stack *stackA = malloc(sizeof(Stack));
    //Stack *stackB = malloc(sizeof(Stack));

    push(stackA, 1);
    push(stackA, 2);
    push(stackA, 3);
    push(stackA, 4);
    print_stack(stackA);
    revers_rotate(stackA);
    print_stack(stackA);

    printf("Size of stack A is: %d\n", stack_size(stackA));
    //printf("Size of stack B is: %d\n", stack_size(stackB));
    if (is_empty(stackA))
        printf("Stack is empty\n");
    free(stackA);
    return (0);
}*/

void create_stack(Stack *stack)
{
    stack->head = NULL;
    stack->tail = NULL;
}

bool is_empty(Stack *stack)
{
    if (stack->head == NULL && stack->tail == NULL)
        return true;
    else 
        return false;
}

void push(Stack *stack, int value)
{
    Node *node = malloc(sizeof(Node));

    node->value = value;
    if(stack->head == NULL)
    {
        stack->tail = node;
        node->next = NULL;
    }
    else
        node->next = stack->head;
    stack->head = node;
}

void peek(Stack *stack)
{
    Node *node = malloc(sizeof(Node));

    if (stack->head == NULL)
        node = stack->tail;
    else
        node = stack->head;
    printf("Peek-> %d\n", node->value);
}

int stack_size(Stack *stack)
{
    Node *node = malloc(sizeof(Node));
    int i = 0;

    if (is_empty(stack))
        return (0);
    else if (stack->head == NULL)
        return (1);
    else
    {
        node = stack->head;
        while (node->next != NULL)
        {
            node = node->next;
            i++;
        }
        return (i + 1);
    }
}

Stack *swap(Stack *stack)
{
    Stack *ret_stack = malloc(sizeof(Stack));
    Node *tmp = malloc(sizeof(Node));

    ret_stack = stack;
    if (stack->head == NULL)
        return false;
    tmp = stack->head;
    stack->head = stack->head->next;
    tmp->next = stack->head->next;
    stack->head->next = tmp;
    return (ret_stack);
}

bool push_over(Stack *stack_A, Stack *stack_B)
{
    Node *tmp = malloc(sizeof(Node));

    if (stack_A->head == NULL && stack_B->head == NULL)
        return false;

    tmp = stack_A->head;
    stack_A->head = stack_A->head->next;
    if (stack_B->head == NULL)
    {
        stack_B->tail = tmp;
        tmp->next = NULL;
    }
    else
        tmp->next = stack_B->head;
    stack_B->head = tmp;

    return true;
}

bool rotate(Stack *stack)
{
    Node *tmp = malloc(sizeof(Node));

    if(stack->head == NULL || is_empty(stack))
        return false;
    tmp = stack->head;
    stack->head = stack->head->next;
    stack->tail->next = tmp;
    stack->tail = tmp;
    tmp->next = NULL;
    
    return true;
}

bool revers_rotate(Stack *stack)
{
    if (stack->head == NULL || is_empty(stack))
        return false;

    Node *current = stack->head;
    while (current->next != stack->tail)
    {
        current = current->next;
    }

    stack->tail->next = stack->head;
    stack->head = stack->tail;
    stack->tail = current;
    stack->tail->next = NULL;

    return true;
}

void print_stack(Stack *stack)
{
    Node *current = stack->head;
    
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
