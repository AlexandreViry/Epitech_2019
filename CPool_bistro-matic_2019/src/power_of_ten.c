#include "../include/my.h"

char *power_of_ten(int i)
{
    char *res;
    int y;

    if ((res = malloc(i + 2)) == NULL)
        malloc_error_message("power_of_ten");
    for (y = 0; y < i; y++)
        res[y] = '0';
    res[y] = '1';
    res[y + 1] = '\0';
    res = my_revstr(res);
    return res;
}
