/*
** EPITECH PROJECT, 2019
** infin_add
** File description:
** add two strings with infinite numbers
*/

#include "include/my.h"

char *multiplier(char *str, char *str2, char *result)
{
    int i;
    char *tmp = "0";
    for (i = 0; str2[i] != '\0'; i++) {
        for (int y = (str2[i] - 48) * my_compute_power_it(10, i); y > 0; y--) {
            result = infin_add(tmp, my_revstr(str));
            tmp = result;
        }
    }
    free(str);
    free(str2);
    return result;
}

char *negative_to_positive(char *str, char *str2, char *result)
{
    str[strlen(str) - 1] = '\0';
    str2[strlen(str2) - 1] = '\0';

    return multiplier(str, str2, result);
}

char *negative_product(char *str, char *str2, char *result)
{
    if (str[strlen(str) - 1] == '\0')
        str[strlen(str) - 1] = '\0';
    if (str2[strlen(str2) - 1] == '\0')
        str2[strlen(str2) - 1] = '\0';
    result = multiplier(str, str2, result);
    return result;
}

char *func_caller(char *str, char *str2, int len)
{
    char *result = malloc(len + 2);

    str = my_revstr(str);
    str2 = my_revstr(str2);
    if (str[strlen(str) - 1] == '-' && str2[strlen(str2) - 1] == '-')
        return (negative_to_positive(str, str2, result));
    if (str[strlen(str) - 1] == '-' || str2[strlen(str2) - 1] == '-')
        return (negative_product(str, str2, result));
    result = multiplier(str, str2, result);
    return result;
}

char *infin_mult(char *str, char *str2)
{
    int value1;
    char *result;

    if (strcmp(str, "0") == 0 || strcmp(str2, "0") == 0)
        return "0";
    value1 = strlen(str) + strlen(str2);
    if (strlen(str) <= strlen(str2))
        result = func_caller(str2, str, value1);
    else
        result = func_caller(str, str2, value1);
    return result;
}
