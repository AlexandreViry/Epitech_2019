/*
** EPITECH PROJECT, 2019
** algorithm
** File description:
** just do it 
*/

#include "./include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include "./include/chained_list.h"

int ra(Chained_list **l_a);
int sa(struct Chained_list *l_a);
int sb(struct Chained_list *l_b);
int verify(int ac, char **av);
void pa(struct Chained_list **l_a, struct Chained_list **l_b);
void pb(struct Chained_list **l_a, struct Chained_list **l_b);

int test_it(Chained_list *l_a)
{
    while (l_a != NULL) {
        if (l_a->nb > l_a->next->nb)
            return (1);
        else
            l_a = l_a->next;
    }
    return (0);
}

int part2(Chained_list **l_a, Chained_list **l_b, int ac)
{
    int i = 3;

    while (i != ac) {
        if ((*l_b)->next == NULL) {
        }
        else if ((*l_b)->nb > (*l_b)->next->nb){
            sb(*l_a);
            pb(l_a, l_b);
            ra(l_a);
        }
        else if((*l_b)->nb <=(*l_b)->next->nb) {
            pb(l_a, l_b);
            ra(l_a);
        }
        i++;
    }
        pa(l_b, l_a);
        ra(l_a);
}

int part1(Chained_list **l_a, Chained_list **l_b, int ac)
{
    int i = 2;

    if (test_it(*l_a) == 0)
        return (0);
    while (i != ac) {
        if ((*l_a)->next == NULL) {
        }
        else if ((*l_a)->nb < (*l_a)->next->nb){
            sa(*l_a);
            pa(l_a, l_b);
        }
        else if((*l_a)->nb >=(*l_a)->next->nb)
            pa(l_a, l_b);    
        i++;
    }
    part2(l_a, l_b, ac);
}
