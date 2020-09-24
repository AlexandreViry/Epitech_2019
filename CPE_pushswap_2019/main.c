#include "include/my.h"

char **init_list(char **l_a, char **av, int ac)
{
    l_a = malloc(sizeof(char *) * ac);
    for (int i = 0; i + 1 < ac; i++)
        l_a[i] = malloc(strlen(av[i + 1]) + 1);
    for (int i = 0; i + 1 < ac; i++)
        strcpy(l_a[i], av[i + 1]);
    l_a[ac - 1] = NULL;
    return l_a;
}

int is_it_ascending_order(char **l_a)
{
    for (int i = 0; l_a[i + 1] != NULL; i++)
        if (atoi(l_a[i]) > atoi(l_a[i + 1]))
            return 1;
    return 0;
}

char **parse_l_a(char **l_a, char **l_b)
{
    while (l_a[1] !=  NULL) {
        if (atoi(l_a[0]) <= atoi(l_a[1]))
            pb(l_a, l_b, 1);
        else {
            l_a = sa(l_a, 1);
            pb(l_a, l_b, 1);
        }
    }
    while (l_b[0] != NULL) {
        if (l_b[1] == NULL || atoi(l_b[0]) >= atoi(l_b[1]))
            pa(l_a, l_b, 1);
        else {
            l_b = sb(l_b, 1);
            pa(l_a, l_b, 1);
        }
    }
    return l_a;
}

char **first_loop(char **l_a, char **l_b)
{
    if (is_it_ascending_order(l_a) == 0)
        return l_a;
    if (atoi(l_a[0]) <= atoi(l_a[1]))
        pb(l_a, l_b, 0);
    else {
        l_a = sa(l_a, 0);
        pb(l_a, l_b, 1);
    }
    while (is_it_ascending_order(l_a) != 0)
        l_a = parse_l_a(l_a, l_b);
    return l_a;
}

void display_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        puts(array[i]);
}

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
}

int main(int ac, char **av)
{
    char **l_a;
    char **l_b;

    if (ac <= 2)
        return 0;
    l_a = init_list(l_a, av, ac);
    l_b = malloc(sizeof(char *) * ac);
    l_b[0] = NULL;
    l_a = first_loop(l_a, l_b);
    free_array(l_b);
    free_array(l_a);
    printf("\n");
    return 0;
}
