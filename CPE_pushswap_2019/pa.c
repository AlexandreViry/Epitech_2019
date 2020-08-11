/*
** EPITECH PROJECT, 2019
** sc
** File description:
** swap the two first element of the l_a and l_b list
*/

#include <stdlib.h>
#include "./include/my.h"
#include "./include/chained_list.h"
#include <stdio.h>

int my_put_in_list(struct Chained_list **list, int nb);

void pa(Chained_list **l_a, Chained_list **l_b)
{
    Chained_list *element = malloc(sizeof(*element));
    Chained_list *temp = *l_a;

    element->nb = (*l_a)->nb;
    element->next = *l_b;
    *l_b = element;
    *l_a = (*l_a)->next;
    free(temp);
    my_putstr("pa ");
}

void pb(Chained_list **l_a, Chained_list **l_b)
{
    Chained_list *element = malloc(sizeof(*element));
    Chained_list *temp = *l_b;
    
    element->nb = (*l_b)->nb;
    element->next = *l_a;
    *l_a = element;
    *l_b = (*l_b)->next;
    free(temp);
    my_putstr("pb ");
}
