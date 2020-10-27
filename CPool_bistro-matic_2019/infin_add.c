/*
** EPITECH PROJECT, 2019
** infin_add
** File description:
** add two strings with infinite numbers
*/

#include "include/my.h"

char *last_carry(char *result, int carry, int count)
{
    int i;
    int y;

    for (int i = 0; i != count; i++)
        result[i] = NTA(result[i]);
    if (carry > 0) {
        result[count] = NTA(carry);
        result[count + 1] = '\0';
    }
    else
        result[count] = '\0';
    result = my_revstr(result);
    for (i = 0; result[i] == '0' && result[i + 1] != '\0'; i++)
        if (result[i] == '\0')
            return result;
    for (y = 0; result[i] != '\0'; y++, i++)
        result[y] = result[i];
    result[y] = '\0';
    return result;
}

char *negative_carry(char *result, int carry, int count)
{
    int i;
    int y;

    if (carry > 0) {
        result[count] = result[count] - carry;
        result[count + 1] = '\0';
    }
    else
        result[count] = 0;
    for (int i = 0; i != count; i++)
        result[i] = NTA(result[i]);
    result = my_revstr(result);
    for (i = 0; result[i] == '0' && result[i + 1] != '\0'; i++)
        if (result[i] == '\0')
            return result;
    for (y = 0; result[i] != '\0'; y++, i++)
        result[y] = result[i];
    result[y] = '\0';
    return result;
}

char *subtractor(char *str, char *str2, char *result)
{
    int carry = 0;
    int count = 0;

    for (int i = 0; str2[i] != '\0' && str[i] != '\0'; i++, count = i) {
        result[i] = str[i] - (str2[i] + carry);
        carry = 0;
        if (result[i] < 0) {
            result[i] += 10;
            carry++;
        }
    }
    for (; str[count] != '\0'; count++) {
        result[count] = ATN(str[count]) - carry;
        carry = 0;
        if (result[count] < 0) {
            result[count] += 10;
            carry++;
        }
    }
    return negative_carry(result, carry, count);
}

char *calculator(char *str, char *str2, char *result)
{
    int carry = 0;
    int count = 0;

    for (unsigned int i = 0; str2[i] != '\0'; i++, count = i) {
        if (i < strlen(str))
            result[i] = str[i] + str2[i] + carry - 96;
        else
            result[i] = str2[i] + carry - 48;
        carry = 0;
        if (result[i] > 9) {
            result[i] -= 10;
            carry++;
        }
    }
    if ((unsigned int)count > strlen(str))
        return last_carry(result, carry, count);
    for (; str[count] != '\0'; count++) {
        result[count] = ATN(str[count]) + carry;
        carry = 0;
        if (result[count] > 9) {
            result[count] -= 10;
            carry++;
        }
    }
    return last_carry(result, carry, count);
}

char *double_negative(char *str, char *str2, char *result)
{
    char *result2;
    int len;
    int i;

    str[strlen(str) - 1] = '\0';
    str2[strlen(str2) - 1] = '\0';
    result = calculator(str, str2, result);
    len = strlen(result);
    if ((result2 = malloc(len + 2)) == NULL)
        malloc_error_message("double_negative");
    result2[0] = '-';
    for (i = 1; result[i] != '\0'; i++)
        result2[i] = result[i - 1];
    result2[i] = result[i - 1];
    result2[len + 1] = '\0';
    return result2;
}

int compare_size(char *str, char *str2)
{
    if (strlen(str) == strlen(str2))
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] < str2[i])
                return 2;
            if (str[i] > str2[i])
                return 1;
        }
    if (strlen(str) > strlen(str2))
        return 1;
    if (strlen(str2) > strlen(str))
        return 2;
    return 1;
}

char *change_sign(char *result)
{
    char *res;
    int i;

    if ((res = malloc(strlen(result) + 2)) == NULL)
        malloc_error_message("change_sign");
    res[0] = '-';
    for (i = 0; result[i] != '\0'; i++)
        res[i + 1] = result[i];
    res[i + 1] = '\0';
    return res;
}

char *negative(char *str, char *str2, char *result)
{
    if (str[strlen(str) - 1] == '-') {
        str[strlen(str) - 1] = '\0';
        if (compare_size(my_revstr(str), my_revstr(str2)) == 2)
            result = subtractor(str2, str, result);
        if (compare_size(my_revstr(str), my_revstr(str2)) == 1) {
            result = subtractor(str, str2, result);
            result = change_sign(result);
        }
    } else {
        str2[strlen(str2) - 1] = '\0';
        if (compare_size(my_revstr(str), my_revstr(str2)) == 1)
            result = subtractor(str, str2, result);
        if (compare_size(my_revstr(str), my_revstr(str2)) == 2) {
            result = subtractor(str2, str, result);
            result = change_sign(result);
        }
    }
    return result;
}

char *func_call(char *str, char *str2, int len)
{
    char *result;

    if ((result = malloc(len + 2)) == NULL)
        malloc_error_message("func_call");
    str = my_revstr(str);
    str2 = my_revstr(str2);
    if (strlen(str) == 0 || strlen(str2) == 0)
        return calculator(str, str2, result);
    if (str2[strlen(str2) - 1] == '-' && str[strlen(str) - 1] == '-')
        return double_negative(str, str2, result);
    else if (str2[strlen(str2) - 1] == '-' || str[strlen(str) - 1] == '-')
        return negative(str, str2, result);
    result = calculator(str, str2, result);
    return result;
}

char *infin_add(char *str, char *str2)
{
    int value1;
    int value2;
    char *result;

    value1 = strlen(str);
    value2 = strlen(str2);
    if (value1 <= value2)
        result = func_call(str2, str, value2);
    else
        result = func_call(str, str2, value1);
    return result;
}
