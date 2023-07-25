/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:29:34 by fptacek           #+#    #+#             */
/*   Updated: 2023/05/22 21:29:36 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int main()
{
    int i;
    int arr[] = {5, 4000, 94448, 542, 1654, 8, 4174, 7722, 6541, 33454, 6, 27, 444, 433, 45465, 456, 1111};
    int size = sizeof(arr) / sizeof(int);

    printf("Array before sort:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    merge_sort(arr, size);

    printf("Array after sort:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}