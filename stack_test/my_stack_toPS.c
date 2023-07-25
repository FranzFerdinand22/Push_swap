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
Stack *insertA(Stack *stack);
Stack *insertB(Stack *stack);
void print(Stack *stackA, Stack *stackB);

//operations
Stack *sa;
Stack *sb;

int main()
{
    Stack *stackA = malloc(sizeof(Stack));
    Stack *stackB = malloc(sizeof(Stack));
    
    insertA(stackA);
    insertB(stackB);
    swap(stackA);
    swap(stackB);
    print(stackA, stackB);
    rotate(stackA);
    revers_rotate(stackB);
    print(stackA, stackB);
    push_over(stackA, stackB);
    print(stackA, stackB);
    printf("Size of stack A: %d\n", stack_size(stackA));
    printf("Size of stack B: %d\n", stack_size(stackB));
    push_over(stackA, stackB);
    print(stackA, stackB);
    printf("Size of stack A: %d\n", stack_size(stackA));
    printf("Size of stack B: %d\n", stack_size(stackB));
    rotate(stackA);
    revers_rotate(stackB);
    print(stackA, stackB);

    if (is_empty(stackA))
        printf("Stack is empty\n");
    free(stackA);
    free(stackB);
    return (0);
}

Stack *insertA(Stack *stack)
{
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    printf("Stack A: ");
    print_stack(stack);
    
    return stack;
}

Stack *insertB(Stack *stack)
{
    push(stack, 990);
    push(stack, 991);
    push(stack, 993);
    push(stack, 994);
    printf("Stack B: ");
    print_stack(stack);
    
    return stack;
}

void print(Stack *stackA, Stack *stackB)
{
    printf("Stack A: ");
    print_stack(stackA);
    printf("Stack B: ");
    print_stack(stackB);
}
