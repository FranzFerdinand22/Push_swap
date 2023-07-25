/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:19:06 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/24 20:05:41 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;

	stack_a = stdin_to_stack(argc, argv);
	print_stack(stack_a);
	if (!stack_a || check_dup(stack_a) == 1)
	{
		free_stack(&stack_a);
		error("empty or dup");
	}
	if (check_sorted(stack_a) != 1)
		sort(&stack_a);
	return (0);
}
