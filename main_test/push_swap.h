#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct _stack {

    long long int   num;
    int           index;
    struct _stack *prev;
    struct _stack *next;
} t_stack;

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

// chec input
t_stack *check_input(int argc, char **argv);
t_stack *single_input(char **argv);
int ft_atoi_ps(const char *str);

// split
char	**ft_split(char const *s, char c);
char	**ft_mysplit(char **split, char const *s, char c);
int	wordcount(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// main utils
void error(char *str);
t_stack *new_node(int num);
t_stack *last_node(t_stack *stack);
void node_to_stack(t_stack **stack, t_stack *node);
int ft_strlen(const char *str);
void print_stack(t_stack *stack);
void print_indexs(t_stack *stack);
void free_arr(char **arr);
int check_dup(t_stack *stack);
void free_stack(t_stack **nodes);
int check_sorted(t_stack *stack);
int stack_size(t_stack *stack);


// sort
void sort(t_stack **stack_A);
void index_num(t_stack *stack_A);
int     *make_arr(t_stack *stack_A);
int binary_Indices(int arr[], int l, int r, int num);
void merge_sort(int arr[], int size);
void merge(int L[], int R[], int arr[], int nL, int nR);
//t_stack **make_stac(int *arr, int size);

// operations
void    pa(t_stack **stack_A, t_stack **stack_B, int i);
void    sa(t_stack **stack_A, int i);
void    ra(t_stack **stack_A, int i);
void    rra(t_stack **stack_A, int i);
void    pb(t_stack **stack_A, t_stack **stack_B, int i);
void    sb(t_stack **stack_B, int i);
void    rb(t_stack **stack_B, int i);
void    rrb(t_stack **stack_B, int i);
void    ss(t_stack **stack_A, t_stack **stack_B, int i);
void    rr(t_stack **stack_A, t_stack **stack_B, int i);
void    rrr(t_stack **stack_A, t_stack **stack_B, int i);

#endif
