/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:34:50 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/17 20:34:51 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int     dec_num_len(int num);
int     *decTobin(int num);


int main(int argc, char **argv)
{
    int a = (atoi(argv[1]));
    int b = (atoi(argv[2]));
    int c = (atoi(argv[3]));
    int and = a & b;
    int or = a | b;
    int xor = a ^ b;
    int rshift = b >> c;
    int lshift = b << c;
    int *bin_a = decTobin(a);
    int *bin_b = decTobin(b);

    printf("\n");
    printf(" -------------------------------\n");
    printf("| Input: a = %d | b = %d | c = %d |\n", a, b, c);
    printf(" -------------------------------\n");
    printf("\n");

    // a -> binary
    printf("a to binary: ");
    for (int i = (dec_num_len(b) - 1); i >= 0; i--)
        printf("%d", bin_a[i]);
    printf("\n");
    
    // b -> binary
    printf("b to binary: ");
    for (int i = (dec_num_len(b) - 1); i >= 0; i--)
        printf("%d", bin_b[i]);
    printf("\n\n");
    
    // a & b
    printf("a & b -> %d\n", and);
    int *bin_and = decTobin(and);
    printf("n in binary: ");
    for (int i = (dec_num_len(b) - 1); i >= 0; i--)
        printf("%d", bin_and[i]);
    printf("\n\n");

    // a | b
    printf("a | b -> %d\n", or);
    int *bin_or = decTobin(or);
    printf("n in binary: ");
    for (int i = (dec_num_len(b) - 1); i >= 0; i--)
        printf("%d", bin_or[i]);   
    printf("\n\n");

    // a ^ b
    printf("a ^ b -> %d\n", xor);
    int *bin_xor = decTobin(xor);
    printf("n in binary: ");
    for (int i = (dec_num_len(b) - 1); i >= 0; i--)
        printf("%d", bin_xor[i]);   
    printf("\n\n");

    // b >> c
    printf("b >> c -> %d\n", rshift);
    int *bin_rsh = decTobin(rshift);
    printf("n in binary: ");
    for (int i = (dec_num_len(b) - 1); i >= 0; i--)
        printf("%d", bin_rsh[i]);
    printf("\n\n");

    // b << c
    printf("b << c -> %d\n", lshift);
    int *bin_lsh = decTobin(lshift);
    printf("n in binary: ");
    for (int i = (dec_num_len(b) - 1); i >= 0; i--)
        printf("%d", bin_lsh[i]);   
    printf("\n");

    printf("-------------------------\n");
    
    return (0);
}



