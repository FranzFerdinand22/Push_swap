/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:16:03 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/21 15:16:04 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct _stack {

    long long int   num;
    int           index;
    struct _stack *next;
} t_stack;

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//main
int main(int argc, char **argv);

//make stack
t_stack *stdin_to_stack(int argc, char **argv);
int ft_atoi_ps(const char *str);



#endif
