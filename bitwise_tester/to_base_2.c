/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_base_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:32:33 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/17 20:32:38 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int     dec_num_len(int num)
{
    int i = 0;

    while (num > 0)
    {
        num = num / 2;
        i++;
    }
    return (i);
}

int     *decTobin(int num)
{
    int i = 0;
    int *arr = malloc(sizeof(int) * (dec_num_len(num) + 1));
    while (num > 0)
    {
        arr[i] = num % 2;
        num = num / 2;
        i++;
    }
    return (arr);
}

/*int     main(int argc, char **argv)
{
    int dec = atoi(argv[1]);
    int *bin = decTobin(dec);

    printf("Decimal: %d\n", dec);
    printf("Binary: ");
    for (int i = (dec_num_len(dec) - 1); i >= 0; i--)
        printf("%d", bin[i]);
    printf("\n");
    return (0);
}*/
