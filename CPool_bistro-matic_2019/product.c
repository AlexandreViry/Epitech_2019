/*
** EPITECH PROJECT, 2019
** infin_add
** File description:
** add two strings with infinite numbers
*/

#include "include/my.h"

char *multiplier(char *str, char *str2, char *result)
{
    int count = 0;
    int y;

    for (int i = 0; str2[i] != '\0'; i++) {
        for (y = 0 + i; str[count] != '\0'; y++, count++) {
            result[y] = ATN(result[y]) + ATN(str2[i]) * ATN(str[count]);
            if (result[y] > 9) {
                result[y + 1] = NTA(result[y] / 10) + ATN(result[y + 1]);
                result[y] = result[y] % 10;
            }
            result[y] = NTA(result[y]);
        }
        count = 0;
    }
    result[y + 1] = '\0';
    result = my_revstr(result);
    result = clear_string(result);
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
    int count;

    for (count = 0; str[count] != '\0'; count++)
        if (str[count] == '-')
            str[count] = '\0';
    for (count = 0; str2[count] != '\0'; count++)
        if (str2[count] == '-')
            str2[count] = '\0';
    result = multiplier(str, str2, result);
    result = change_sign(result);
    return result;
}

char *func_caller(char *str, char *str2, int len)
{
    char *result;

    if ((result = malloc(len)) == NULL)
        malloc_error_message("negative_product");
    for (int i = 0; i < len; i++)
        result[i] = '0';
    result[len - 1] = '\0';
    str = my_revstr(str);
    str2 = my_revstr(str2);
    if (str[strlen(str) - 1] == '-' && str2[strlen(str2) - 1] == '-')
        return (negative_to_positive(str, str2, result));
    if (str[strlen(str) - 1] == '-' || str2[strlen(str2) - 1] == '-')
        return (negative_product(str, str2, result));
    if (strlen(str) > strlen(str2))
        return multiplier(str, str2, result);
    result = multiplier(str2, str, result);
    return result;
}

char *infin_mult(char *str, char *str2)
{
    int value1;
    char *result;
    char *tmp = malloc(2);

    if (tmp == NULL)
        malloc_error_message("infin_mult");
    tmp[0] = '0';
    tmp[1] = '\0';
    if (strcmp(str, "0") == 0 || strcmp(str2, "0") == 0)
        return tmp;
    value1 = strlen(str) + strlen(str2) + 3;
    if (strlen(str) <= strlen(str2))
        result = func_caller(str2, str, value1);
    else
        result = func_caller(str, str2, value1);
    return result;
}
