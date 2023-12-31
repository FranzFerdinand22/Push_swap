/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:16:03 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/25 18:59:30 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct _stack	t_stack;

typedef struct _stack
{
	long long int		num;
	int					index;
	t_stack				*next;
}	t_stack;

//ft_pritf

//main + utils
int		main(int argc, char **argv);
int		ft_strcmp(const char *s1, const char *s2);
void	error(char *str);
int		check_dup(t_stack *stack_A);
void	free_stack(t_stack **nodes);

//stdin to stack
t_stack	*stdin_to_stack(int argc, char **argv);
int		ft_atoi_ps(const char *str);

//stack utils
t_stack	*new_node(int num);
t_stack	*last_node(t_stack *stack);
t_stack	*node_to_stack(t_stack **stack, t_stack *node);
void	print_stack(t_stack *stack);
void	free_arr(char **arr);
int		check_sorted(t_stack *stack);

//split
char	**ft_split(char const *s, char c);
char	**ft_mysplit(char **split, char const *s, char c);
int		wordcount(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

// sort
int		stack_size(t_stack *stack);
void	index_nbrs(t_stack *stack_A);
int		*make_arr(t_stack *stack);
void	index_nbrs(t_stack *stack_A);
void	sort(t_stack **stack_A);
void	print_indexs(t_stack *stack);
//void	merge_sort(int arr[], int size);
//void	merge(int L[], int R[], int arr[], int nL, int nR);
void	radix_sort(t_stack **stack_A, t_stack **stack_B);
void	bitwise_part(t_stack **stack_A, t_stack **stack_B, int max_bits);
void	bubble_sort(int arr[], int n);

// operations a
void	pa(t_stack **stack_A, t_stack **stack_B, int i);
void	sa(t_stack **stack_A, int i);
void	ra(t_stack **stack_A, int i);
void	rra(t_stack **stack_A, int i);

// operations b
void	pb(t_stack **stack_A, t_stack **stack_B, int i);
void	sb(t_stack **stack_B, int i);
void	rb(t_stack **stack_B, int i);
void	rrb(t_stack **stack_B, int i);

// operations ab
void	ss(t_stack **stack_A, t_stack **stack_B, int i);
void	rr(t_stack **stack_A, t_stack **stack_B, int i);
void	rrr(t_stack **stack_A, t_stack **stack_B, int i);

#endif
