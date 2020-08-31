#include "../include/my.h"

char *power_of_ten(int i)
{
    char *res = malloc(i + 2);
    int y;

    for (y = 0; y < i; y++)
        res[y] = '0';
    res[y] = '1';
    res[y + 1] = '\0';
    res = my_revstr(res);
    return res;
}
