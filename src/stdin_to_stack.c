/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:23:12 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/24 20:43:43 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//special atoi for push swap
int	ft_atoi_ps(const char *str)
{
	int	minus;
	int	res;

	res = 0;
	minus = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f' \
			|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			error("badnum");
		if (res > (INT_MAX - (*str - '0')) / 10)
			error("badnum");
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * minus);
}

//split string to single input -> return stack
t_stack	*single_input(char **argv)
{
	int		i;
	int		j;
	char	**arr;
	t_stack	*stack_a;

	i = 0;
	j = 0;
	stack_a = NULL;
	arr = ft_split(argv[1], ' ');
	while (arr[i])
	{
		j = ft_atoi_ps(arr[i]);
		node_to_stack(&stack_a, new_node(j));
		i++;
	}
	free_arr(arr);
	return (stack_a);
}

//check the input -> make stack from input -> returns stack
t_stack	*stdin_to_stack(int argc, char **argv)
{
	int		i;
	int		j;
	t_stack	*stack_a;

	i = 1;
	j = 0;
	stack_a = NULL;
	if (argc < 2)
		error("stdin");
	else if (argc == 2)
		stack_a = single_input(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi_ps(argv[i]);
			node_to_stack(&stack_a, new_node(j));
			i++;
		}
	}
	return (stack_a);
}
