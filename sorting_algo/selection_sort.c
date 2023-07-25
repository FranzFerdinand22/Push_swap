/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:42:42 by fptacek           #+#    #+#             */
/*   Updated: 2023/05/22 18:42:43 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    selection_sort(int arr[], int n)
{
    int i = 0;
    int j = 0;
    int min_i= 0;
    int temp = 0;

    while (i < n - 1)
    {
        min_i = i;
        j = i + 1;
        while (j < n)
        {
            if (arr[j] < arr[min_i])
                min_i = j;
            j++;
        }
        temp = arr[i];
        arr[i] = arr[min_i];
        arr[min_i] = temp;
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

    selection_sort(arr, 6);

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
