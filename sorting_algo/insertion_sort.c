/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:58:42 by fptacek           #+#    #+#             */
/*   Updated: 2023/05/22 19:58:43 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    insertion_sort(int arr[], int n)
{
    int i = 1;
    int value = 0;
    int hole = 0;

    while (i < n)
    {
        value = arr[i];
        hole = i;
        while (hole > 0 && arr[hole - 1] > value)
        {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = value;
        i++;
    }
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

    insertion_sort(arr, 6);

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