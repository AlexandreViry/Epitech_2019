#include "include/my.h"

char **sa(char **l_a, int draw)
{
    int i;
    char *tmp = l_a[0];

    if (tmp == NULL || l_a[1] == NULL)
        return l_a;
    l_a[0] = l_a[1];
    l_a[1] = tmp;
    if (draw == 1)
        printf(" sa");
    else
        printf("sa");
    return l_a;
}
