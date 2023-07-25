/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:16:00 by fptacek           #+#    #+#             */
/*   Updated: 2023/05/22 19:16:01 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    bubble_sort(int arr[], int n)
{
    int i = 0;
    int k = 1;
    int temp = 0;

    while (k < n)
    {
        i = 0;
        while (i < n - 1)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
            i++;
        }
        k++;
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

    bubble_sort(arr, 6);

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
