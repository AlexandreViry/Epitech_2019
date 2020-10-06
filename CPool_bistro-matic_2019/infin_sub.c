/*
** EPITECH PROJECT, 2019
** infin_add
** File description:
** sub two strings with infinite numbers
*/

#include "include/my.h"

char *sub_negative(char *str, char *str2, char *result)
{
    char *result2;
    int len;
    int i;

    result = calculator(str, str2, result);
    len = strlen(result);
    if ((result2 = malloc(len + 2)) == NULL)
        malloc_error_message("sub_negative");
    result2[0] = '-';
    for (i = 1; result[i] != '\0'; i++)
        result2[i] = result[i - 1];
    result2[i] = result[i - 1];
    result2[len + 1] = '\0';
    return result2;
}

char *check_negative(char *str, char *str2, char *result)
{
    str2 = change_sign(my_revstr(str2));
    str2 = my_revstr(str2);
    result = negative(str, str2, result);
    return result;
}

char *sub_func_call(char *str, char *str2, int len)
{
    char *result;

    if ((result = malloc(len + 2)) == NULL)
        malloc_error_message("sub_func_call");
    str = my_revstr(str);
    str2 = my_revstr(str2);
    if (str2[strlen(str2) - 1] == '-' && str[strlen(str) - 1] != '-') {
        str2[strlen(str2) -1] = '\0';
        return infin_add(my_revstr(str), my_revstr(str2));
    }
    if (str2[strlen(str2) - 1] != '-' && str[strlen(str) - 1] != '-')
        return check_negative(str, str2, result);
    if (str2[strlen(str2) - 1] != '-' && str[strlen(str) - 1] == '-') {
        str[strlen(str) - 1] = '\0';
        return sub_negative(str, str2, result);
    }
    if (str2[strlen(str2) - 1] == '-' && str[strlen(str) - 1] == '-') {
        str2[strlen(str2) -1] = '\0';
        return infin_add(my_revstr(str), my_revstr(str2));
    }
    return str;
}

char *infin_sub(char *str, char *str2)
{
    int value1;
    int value2;
    char *result;

    value1 = strlen(str);
    value2 = strlen(str2);
    if (value1 <= value2)
        result = sub_func_call(str, str2, value2);
    else
        result = sub_func_call(str, str2, value1);
    return result;
}
