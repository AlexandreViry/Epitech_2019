/*
** EPITECH PROJECT, 2019
** main
** File description:
** call all the functions
*/

#include "./include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include "./include/chained_list.h"

int ra(Chained_list **l_a);
int sa(struct Chained_list *l_a);
int verify(int ac, char **av);
void pa(struct Chained_list **l_a, struct Chained_list **l_b);
void pb(struct Chained_list **l_a, struct Chained_list **l_b);

int my_put_in_list(Chained_list **list, int nb)
{
    Chained_list *element1 = malloc(sizeof(*element1));
    element1->nb = nb;
    element1->next = *list;
    *list = element1;
    return (0);
}

int my_param_to_list(Chained_list **list, char **str, int ac)
{
    for (int i = ac - 1; i != 0 ; i--) {
        int nb = my_atoi(str[i]);
        my_put_in_list(list, nb);
    }
    return (0);
}

void my_show_list(Chained_list *list)
{
    Chained_list *tmp = list;

    while (tmp != NULL) {
        my_put_nbr(tmp->nb);
        my_putchar(' ');
        tmp = tmp->next;
    }
}

int main(int ac, char **av)
{
    if (verify(ac, av) == 0)
        return (0);
    Chained_list *l_a = malloc(sizeof(*l_a));
    l_a = NULL;
    Chained_list *l_b = malloc(sizeof(*l_b));
    l_b = NULL;
    my_param_to_list(&l_a, av, ac);
    part1(&l_a, &l_b, ac);
    my_putchar('\n');
    return (0);
}
