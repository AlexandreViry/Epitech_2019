/*
** EPITECH PROJECT, 2019
** sb
** File description:
** swap the two first element of the l_b list
*/

#include <stdlib.h>
#include "./include/my.h"
#include "./include/chained_list.h"

int sb(struct Chained_list *l_b)
{
    int temp = l_b->nb;
    l_b->nb = l_b->next->nb;
    l_b = l_b->next;
    l_b->nb = temp;
    my_putstr("sb ");
    return (0);
}
