#include "include/my.h"

char *recup_str_before_parentheses(char *str, unsigned int start)
{
    char *new_string;

    if (start >= strlen(str) - 1 || start == 0)
        return "\0";
    if (start > 0)
        new_string = malloc(start + 2);
    for (unsigned int tmp = 0; tmp < start; tmp++)
        new_string[tmp] = str[tmp];
    if ((new_string[start - 1] >= '0' && new_string[start - 1] < '9') ||
        new_string[start - 1] == ')')
            new_string[start] = '*';
    else
        new_string[start] = '\0';
    new_string[start + 1] = '\0';
    return new_string;
}

char *end_of_str(char *str, int end)
{
    unsigned int nb = 0;
    char *new_string;

    if (str[end] == '\0')
        return "\0";
    new_string = malloc(strlen(str) - end + 2);
    if (end > 0 && str[end - 1] == ')' &&
        str[end + 1] != '(' && str[end] != ')') {
        nb = 1;
        new_string[0] = '*';
    }
    for (; str[end] != '\0' ; nb++, end++)
        new_string[nb] = str[end];
    new_string[nb] = '\0';
    return new_string;
}

char *calc_parentheses(char *result, char *str, int start, int end)
{
    int tmp;

    for (tmp = 0; start < end; tmp++, start++)
        result[tmp] = str[start];
    result[tmp] = '\0';
    for (int i = 0; result[i] != '\0'; i++)
        if (result[i] > '9' || result[i] < '0') {
            result = eval_expr(result);
            i = 0;
        }
    return result;
}

char *parentheses_loop(char *str)
{
    char *result;
    char *new_string;
    int start;
    int end;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '(') {
            for (start = i; str[start] != '('; start++);
            for (end = start; str[end] != ')'; end++)
                if (str[end] == '(') {
                    start = end;
                    i = 0;
                }
            result = malloc(end - start);
            result = calc_parentheses(result, str, start + 1, end);
            new_string = recup_str_before_parentheses(str, start);
            result = my_strcat(new_string, result);
            result = my_strcat(result, end_of_str(str, end + 1));
            str = result;
        }
    return result;
}

int check_parentheses(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '(' ||str[i] == ')')
            return 1;
    return 0;
}

char *parentheses(char *str)
{
    int count = 0;
    char *result = str;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            count++;
    }
    if (count == 0)
        return str;
    while (check_parentheses(result) != 0)
        result = parentheses_loop(result);
    return result;
}
