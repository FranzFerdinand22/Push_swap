/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:39:01 by fptacek           #+#    #+#             */
/*   Updated: 2023/05/22 20:39:03 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     lenght_arr(int arr[])
{
    int     len = 0;

    len = (sizeof(arr) / sizeof(int));
    return (len);
}

void  merge(int L[], int R[], int arr[])
{
    int nL;
    int nR;
    int i = 0;
    int j = 0;
    int k = 0;
    
    nL = lenght_arr(L);
    nR = lenght_arr(R);

    while (i < nL && j < nR)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    while (i < nL)
    {
        arr[k] = L[i];
        i++;
        k++;
    }    
    while (j < R[j])
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void    merge_sort(int arr[])
{
    int n;
    int i = 0;
    int mid;
    int *left_arr;
    int *right_arr;

    n = lenght_arr(arr);
    if(n < 2)
        return ;
    mid = n / 2;
    left_arr[mid];
    right_arr[n - mid];
    while (i < mid -1)
    {
        left_arr[i] = arr[i];
        i++;
    }
    i = mid;
    while (i < n - 1)
    {
        right_arr[i - mid] = arr[i];
        i++;
    }
    merge_sort(left_arr);
    merge_sort(right_arr);
    merge(left_arr, right_arr, arr);
}


int     main()
{
    int     i = 0;
    int     arr[] = {5,4,9,2,1,7};

    printf("Array before sort: \n");
    while (i < 6)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
    printf("\n");

    merge_sort(arr);

    i = 0;
    printf("Array after sort: \n");
    while (i < 6)
    {
        printf("%d ", arr[i]);
        i++;;
    }
    printf("\n");

    return (0);
}