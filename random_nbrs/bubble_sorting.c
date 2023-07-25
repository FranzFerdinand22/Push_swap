/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:56:39 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/10 18:56:41 by fptacek          ###   ########.fr       */
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
