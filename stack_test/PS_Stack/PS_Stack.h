/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_Stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:35:15 by fptacek           #+#    #+#             */
/*   Updated: 2023/06/29 17:35:16 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    int num;
    struct _node *next;
} Node;

typedef struct _stack {
    Node *head;
    Node *tail;
} Stack;

void initializeStack(Stack *stack);
void push(Stack *stack, int num);
int getMaxNumWidth(int num);
int getMaxNumWidth(int num);


#endif