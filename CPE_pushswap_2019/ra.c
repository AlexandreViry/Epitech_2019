/*
** EPITECH PROJECT, 2019
** ra
** File description:
** the first element will become the last
*/

#include <stdlib.h>
#include "./include/my.h"
#include "./include/chained_list.h"
#include <stdio.h>

int ra(Chained_list **l_a)
{
    Chained_list *head = malloc(sizeof(*head));
    head->nb = (*l_a)->nb;
    Chained_list *tmp = *l_a;
    Chained_list *dest = *l_a;
    
    while (dest->next != NULL)
        dest = dest->next;
    dest->next = head;
    *l_a = (*l_a)->next;
    my_putstr("ra ");
}
