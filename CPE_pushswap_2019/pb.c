#include "include/my.h"

void pb(char **l_a, char **l_b, int draw)
{
    int i;
    char *tmp = l_a[0];
    char *tmp2 = l_b[0];

    if (draw == 0)
        printf("pb");
    else
        printf(" pb");
    for (i = 0; l_a[i] != NULL; i++)
        l_a[i] = l_a[i + 1];
    l_a[i] = NULL;
    if (tmp2 == NULL) {
        l_b[0] = tmp;
        l_b[1] = NULL;
        return;
    }
    for (i = 0; l_b[i] != NULL; i++);
    for (int y = i; y > 0; y--)
        l_b[y] = l_b[y - 1];
    l_b[0] = tmp;
    l_b[i + 1] = NULL;
}

void pa(char **l_a, char **l_b, int draw)
{
    int i;
    char *tmp = l_b[0];
    char *tmp2 = l_a[0];

    if (draw == 0)
        printf("pa");
    else
        printf(" pa");
    for (i = 0; l_b[i] != NULL; i++)
        l_b[i] = l_b[i + 1];
    l_b[i] = NULL;
    if (tmp2 == NULL) {
        l_a[0] = tmp;
        l_a[1] = NULL;
        return;
    }
    for (i = 0; l_a[i] != NULL; i++);
    for (int y = i; y > 0; y--)
        l_a[y] = l_a[y - 1];
    l_a[0] = tmp;
    l_a[i + 1] = NULL;
}
