#include "../include/my.h"

char *clear_string(char *result)
{
    int i;
    int y;

    for (i = 0; result[i] == '0' && result[i + 1] != '\0'; i++)
        if (result[i] == '\0')
            return result;
    for (y = 0; result[i] != '\0'; y++, i++)
        result[y] = result[i];
    result[y] = '\0';
    return result;
}
