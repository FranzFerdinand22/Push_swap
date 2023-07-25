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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *collection;
    int capacity;
    int size;
} Stack;

Stack *create_stack(int capacity);
void destroy_stack(Stack *stack);
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
bool pop(Stack *stack, int *item);
bool push(Stack *stack, int item);
bool peek(Stack *stack, int *item);

int main()
{
    Stack *stack;

    stack = create_stack(5);
    if (stack == NULL)
    {
        printf("Error creating stack. \n");
        return (1);
    }
    if (is_empty(stack))
        printf("Stack is empty\n");

    push(stack, 2);
    push(stack, 9);
    push(stack, 4);
    push(stack, 7);
    push(stack, 8);
    printf("Stack size: %d\n", stack->size);
    if (is_full(stack))
        printf ("Stack is full!\n");
    int peek_val = 0;
    peek(stack, &peek_val);
    printf("Value of item: %d\n", peek_val);
    int pop_val = 0;
    for (int i = 0; i < 5; i++)
    {
        pop(stack, &pop_val);
        printf("Popped value: %d\n", pop_val);
    }
    if (is_empty(stack))
        printf("Stack is empty\n");
    destroy_stack(stack);
    return (0);
}

Stack *create_stack(int capacity)
{
    if (capacity <= 0)
        return NULL;
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL)
        return NULL;
    stack->collection = malloc(sizeof(int) * capacity);
    if (stack->collection == NULL)
    {
        free(stack);
        return NULL;
    }    
    stack->capacity = capacity;
    stack->size = 0;
    return stack;
}

void destroy_stack(Stack *stack)
{
    free(stack->collection);
    free(stack);
}

bool is_full(Stack *stack)
{
    return (stack->capacity == stack->size);
}

bool is_empty(Stack *stack)
{
    return (stack->size == 0);
}

bool push(Stack *stack, int item)
{
    if (is_full(stack))
        return false;
    stack->collection[stack->size] = item;
    stack->size++;

    return true;
}

bool peek(Stack *stack, int *item)
{
    if (is_empty(stack))
        return false;
    *item = stack->collection[stack->size - 1];
    return true;
}

bool pop(Stack *stack, int *item)
{
    if (is_empty(stack))
        return false;
    stack->size--;
    *item = stack->collection[stack->size];
}