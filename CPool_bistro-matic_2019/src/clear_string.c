#include "../include/my.h"

char *clear_string(char *str)
{
    int i;
    char *result;
    int y;

    if (str[0] == '0' && str[1] != '\0') {
        for (i = 0; str[i] == '0' && str[i] != '\0'; i++);
        result = malloc(i + 1);
        for (y = 0; str[i] == '0' && str[i] != '\0'; i++, y++)
            result[y] = str[i];
        result[y] = '\0';
    }
    return result;
}
