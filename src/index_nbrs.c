/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:54:38 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/23 13:54:39 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// merging two subarrays L and R into a single sorted array
void merge(int L[], int R[], int arr[], int nL, int nR)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0; 
    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
        k++;
    }
    while (i < nL)
        arr[k++] = L[i++];

    while (j < nR)
        arr[k++] = R[j++];
}

// divides the array into two halves -> recursively sorts them 
void merge_sort(int arr[], int size)
{
    if (size < 2)
        return ;
    int mid;
    int i;
    int left_arr[size / 2];
    int right_arr[size - (size / 2)];
    
    i = 0;
    mid = size / 2;
    while (i < mid)
    {
        left_arr[i] = arr[i];
        i++;
    }
    i = mid;
    while (i < size)
    {
        right_arr[i - mid] = arr[i];
        i++;
    }
    merge_sort(left_arr, mid);
    merge_sort(right_arr, size - mid);
    merge(left_arr, right_arr, arr, mid, size - mid);
}

// Binary Search -> find the index of element in a sorted array
int binary_Indices(int arr[], int l, int r, int num) 
{
    int m;

    while (l <= r) 
    {
        m = l + (r - l) / 2;
        if (arr[m] == num)
            return m;
        if (arr[m] < num)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

// making array form stack
int *make_arr(t_stack *stack)
{
    int len;
    int *arr;
    int i;

    i = 0;
    len = stack_size(stack);
    arr = malloc(sizeof(int) * (len + 1));
    if (arr == NULL)
        return (0);
    while (stack != NULL)
    {
        arr[i] = stack->num;
        stack = stack->next;
        i++;
    }
    return (arr);
}

// assigns the indices to the elements in the stack
void index_nbrs(t_stack *stack_A)
{
    int i;
    int index;
    int *input;
    int size;
    int* copy;

    i = 0;
    index = 0;
    input = make_arr(stack_A);
    size = stack_size(stack_A);
    copy = malloc((size + 1) * sizeof(int));
    while (i < size)
    {
        copy[i] = input[i];
        i++;
    }
    merge_sort(copy, size);
    i = 0;
    while (i < size)
    {
        index = binary_Indices(copy, 0, size - 1, input[i++]);
        stack_A->index = index;
        stack_A = stack_A->next;
    }
    free(copy);
}