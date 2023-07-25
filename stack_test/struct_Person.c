/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_Person.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:15:16 by fptacek           #+#    #+#             */
/*   Updated: 2023/06/25 21:15:23 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _person {
    char *firstName;
    char *lastName;
    char *title;
    unsigned int age;
} Person;

/*void initializePerson(Person *person, const char *fn, const char *ln, const char *title, unsigned int age)
{
    person->firstName = (char *)malloc(strlen(fn) + 1);
    strcpy(person->firstName, fn);
    person->lastName = (char *)malloc(strlen(ln) + 1);
    strcpy(person->lastName, ln);
    person->title = (char *)malloc(strlen(title) + 1);
    strcpy(person->title, title);
    person->age = age;
}*/

void processPerson(Person *person)
{
    char firstName[50];
    char lastName[50];
    char title[50];

    printf("First name: ");
    scanf("%49s", firstName);
    person->firstName = (char *)malloc(strlen(firstName) + 1);
    strcpy(person->firstName, firstName);

    printf("Last name: ");
    scanf("%49s", lastName);
    person->lastName = (char *)malloc(strlen(lastName) + 1);
    strcpy(person->lastName, lastName);

    printf("Title: ");
    scanf("%49s", title);
    person->title = (char *)malloc(strlen(title) + 1);
    strcpy(person->title, title);

    printf("Age: ");
    scanf("%d", &(person->age));
}

void deallocatePerson(Person *person)
{
    free(person->firstName);
    free(person->lastName);
    free(person->title);
}

int main()
{
    Person *person = (Person *)malloc(sizeof(Person));
    printf("-------------------\n\n");
    processPerson(person);

    printf("\n-------------------\n\n");
    printf("First name: %s\n", person->firstName);
    printf("Last name: %s\n", person->lastName);
    printf("Title: %s\n", person->title);
    printf("Age: %d\n", person->age);
    printf("\n-------------------\n");
    deallocatePerson(person);

    free(person);
    return (0);
}
