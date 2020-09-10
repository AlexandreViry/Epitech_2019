#include "include/my.h"

char *create_new_str(char *str, unsigned int start)
{
    char *new_string;

    if (start >= strlen(str) - 1)
        return "\0";
    if (start > 0)
        new_string = malloc(start + 2);
    for (unsigned int tmp = 0; tmp < start; tmp++)
        new_string[tmp] = str[tmp];
    if ((new_string[start - 1] >= '0' && new_string[start - 1] < '9') ||
        new_string[start - 1] == '(' || new_string[start - 1] ==')')
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
    new_string = malloc(strlen(str) - end + 1);
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

int analyse_parentheses(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '(')
            return 1;
    return 0;
}

char *parentheses_loop(char *str)
{
    char *result;
    char *new_string;
    int start;
    int end;

    for (start = 0; str[start] != '('; start++)
        if (str[start] == '\0')
            return str;
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
            new_string = create_new_str(str, start);
            result = my_strcat(new_string, result);
            result = my_strcat(result, end_of_str(str, end + 1));
            free(new_string);
            str = result;
        }
    return result;
}

char *parentheses(char *str)
{
    int count = 0;
    char *result;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            count++;
    }
    if (count == 0)
        return str;
    result = parentheses_loop(str);
    return result;
}
