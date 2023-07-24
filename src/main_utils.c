/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:15:54 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/21 17:15:56 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"      

int     ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == '\0')
			return (0);
	return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
}

void    error(char *str)
{
    if (ft_strcmp(str, "stdin") == 0)
        write(1, "Error: Wrong input\n", 20);
    else if (ft_strcmp(str, "badnum") == 0)
    {
        write(1, "Error: Wrong number\n", 21);
        exit(1);
    }
    else if (ft_strcmp(str, "empty or dup") == 0)
    {
        write(1, "Error: Duplicate number or empty stack\n", 40);
        exit(1);
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

// checking duplicate number from stdin -> boolen
int check_dup(t_stack *stack_A)
{
    t_stack *tmp;

    while (stack_A != NULL)
    {
        tmp = stack_A->next;
        while (tmp != NULL)
        {
            if (tmp->num == stack_A->num)
                return (1);
            tmp = tmp->next;
        }
        stack_A = stack_A->next;
    }
    return (0);
}

void free_stack(t_stack **nodes)
{
    t_stack *next_node;

    if (!nodes)
        return ;
    while (*nodes)
    {
        next_node = (*nodes)->next;
        (*nodes)->num = 0;
        free(*nodes);
        (*nodes) = next_node;
    }
}