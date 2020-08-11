/*
** EPITECH PROJECT, 2019
** sa
** File description:
** swap the two first element of the l_a list
*/

#include <stdlib.h>
#include "./include/my.h"
#include "./include/chained_list.h"

int sa(Chained_list *l_a)
{
    int temp = l_a->nb;
    l_a->nb = l_a->next->nb;
    l_a = l_a->next;
    l_a->nb = temp;
    my_putstr("sa ");
    return (0);
}
