/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:43:51 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/13 19:43:52 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void merge(int L[], int R[], int arr[], int nL, int nR)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nL)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < nR)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int size)
{
    if (size < 2)
        return;

    int mid = size / 2;
    int left_arr[mid];
    int right_arr[size - mid];
    int i;

    for (i = 0; i < mid; i++)
    {
        left_arr[i] = arr[i];
    }

    for (i = mid; i < size; i++)
    {
        right_arr[i - mid] = arr[i];
    }

    merge_sort(left_arr, mid);
    merge_sort(right_arr, size - mid);
    merge(left_arr, right_arr, arr, mid, size - mid);
}

int binary_Indices(int arr[], int l, int r, int num)
{
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (arr[m] == num)
			return m;
		if (arr[m] < num)
			l = m + 1;
		else
			r = m - 1;
	}

	return -1;
}

int *make_arr(t_stack *stack_A)
{
    int i = 0;
    int size = stack_size(stack_A);
    int *arr = malloc(sizeof(int) * size);

    while (stack_A != NULL)
    {
        arr[i] = stack_A->num;
        stack_A = stack_A->next;
        i++;
    }
    return arr;
}

void index_num(t_stack *stack_A)
{
    int *input = make_arr(stack_A);
    int size = stack_size(stack_A);

    printf("Array before index: ");
    for (int i = 0; i < size; i++)
        printf("%d,", input[i]);
    printf("\n"); 

    int* copy = malloc((size + 1) * sizeof(int));
    if (copy == NULL)
        return ;
    
    for (int i = 0; i < size; ++i) {
        copy[i] = input[i];
    }

    clock_t start_time = clock(); // Start the timer

    merge_sort(copy, size);

    int index = 0;
    for (int j = 0; j < size; ++j)
    {
        index = binary_Indices(copy, 0, size - 1, input[j]);
        stack_A->index = index;
        stack_A = stack_A->next;
    }
    clock_t end_time = clock(); // Stop the timer

    /*printf("Array after index: ");
    printArray(input, size);*/

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution time: %.6f seconds\n", execution_time);
    
    free(copy);
}