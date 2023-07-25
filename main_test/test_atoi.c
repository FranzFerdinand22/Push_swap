#include <stdio.h>
#include "push_swap.h"

int ft_atoi_ps(const char *str)
{
    int minus;
    int res;

    res = 0;
    minus = 1;
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f' || *str == '\v' || *str == '\r')
        str++;
    if(*str == '+' || *str == '-')
    {
        if (*str == '-')
            minus = -1;
        str++;
    }
    while (*str)
    {
        if (*str < '0' || *str > '9')
            error("badnum");
        else
            res = res * 10 + (*str - '0');
        str++;
    }
    if ((res * minus) > 2147483647 || (res * minus) < -2147483648)
		error("badnum");
    return (res * minus);
}

int main()
{
    char *arr = "5a";

    printf("From ASCII: %s to integeer: %d\n", arr, ft_atoi_ps(arr));

    return (0);
}