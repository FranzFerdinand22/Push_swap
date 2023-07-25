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

#include "PS_Stack.h"

// Stack operations
void initializeStack(Stack *stack)
{
    stack->head = NULL;
    stack->tail = NULL;
}

void push(Stack *stack, int num)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->num = num;
    if (stack->head == NULL)
    {
        stack->tail = node;
        node->next = NULL;
    }
    else
        node->next = stack->head;
    stack->head = node;
}

void swap(Stack *stack)
{
    Node *node;
    
    if (stack->head != NULL && stack->head->next != NULL)
    {
        node = stack->head;
        stack->head = stack->head->next;
        node->next = stack->head->next;
        stack->head->next = node;
    }
}
//end of Stack operations

//graphical sort part
int getMaxNumWidth(int num)
{
    int width = 1;
    while (num / 10 != 0)
    {
        width++;
        num /= 10;
    }
    return width;
}

void printTableLine(int width)
{
    for (int i = 0; i < width; i++)
    {
        printf("-");
    }
}
//end of grapical stuff

int main(int argc, char **argv)
{
    Stack stack_A;
    Stack stack_B;
    int i = 1;

    initializeStack(&stack_A);
    initializeStack(&stack_B);

    while (i < argc)
    {
        push(&stack_A, atoi(argv[i]));
        i++;
    }
    Node *node = stack_A.head;
    Node *emp = stack_B.head;
    int maxNumWidth = 0;

    swap(&stack_A);

    i = 1;
    while (i <= argc && node != NULL)
    {
        int numWidth = getMaxNumWidth(node->num);
        if (numWidth > maxNumWidth)
        {
            maxNumWidth = numWidth;
        }
        node = node->next;
        i++;
    }

    node = stack_A.head;

    i = 1;
    while (i <= argc && node != NULL)
    {
        int numWidth = getMaxNumWidth(node->num);
        printf("%-*d  %-*s\n", maxNumWidth, node->num, maxNumWidth, (emp != NULL) ? "" : " ");
        node = node->next;
        i++;
    }

    printTableLine(maxNumWidth);
    printf("  ");
    printTableLine(maxNumWidth);
    printf("\n");

    printf("%-*s  %-*s\n", maxNumWidth, "a", maxNumWidth, "b");

    return (0);
}
