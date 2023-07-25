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

#include <unistd.h>
#include <string.h>

struct Date { short day, month, year; };

typedef struct Harcovnik 
{
    char name [64];
    char surname [32];
    int  group;
    struct Date born;
}Harcovnik_t;

typedef struct Setnina
{
    Harcovnik_t harcovnik;
    Setnina_t *pNext;
}Setnina_t;

Harcovnik_t h1, h2, *pHarcovnik = &h1;

strcpy(h1.name, "Jan");
strcpy(h1.surname, "Zacharias");
h1.group = 3;
h1.born.day = 15;
h1.born.month = 3;
h1.born.year = 2009;

if ((*pHarcovnik).group != 2 || (*pHarcovnik).group != 3)
    printf("Harcovnik %s %s jiz neni dite.\n", (pHarcovnik).name, (pHarcovnik).surname);