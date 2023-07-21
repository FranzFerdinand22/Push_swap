/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:15:54 by fptacek           #+#    #+#             */
/*   Updated: 2023/07/21 17:15:56 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (*(str++))
        i++;
    return (i);
}*/       

int     ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == '\0')
			return (0);
	return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
}

void    error(char *str)
{
    if (ft_strcmp(str, "stdin") == 0)
        write(1, "Error: Wrong input\n", 21);
    else if (ft_strcmp(str, "stdin") == 0)
        write(1, "Error: Wrong number\n", 22);
}
