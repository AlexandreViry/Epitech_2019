#include "include/my.h"

/* This function returns a string which contains all the characters before
   the parenthesis located at start pointer. */

char *recup_str_before_parentheses(char *str, unsigned int start)
{
    char *new_string;

    if (start >= strlen(str) - 1 || start == 0)
        return "\0";
    if (start > 0)
        if ((new_string = malloc(start + 2)) == NULL)
            malloc_error_message("recup_str_before_parentheses");
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

/* This function returns a string which contains all the characters located
   after the closing parenthesis located at the end pointer. */

char *end_of_str(char *str, int end)
{
    unsigned int nb = 0;
    char *new_string;

    if (str[end] == '\0')
        return "\0";
    if ((new_string = malloc(strlen(str) - end + 2)) == NULL)
        malloc_error_message("end_of_str");
    if (end > 0 && str[end - 1] == ')' &&
        (str[end + 1] > '9' || str[end + 1] < '0') && str[end] != ')') {
        nb = 1;
        new_string[0] = '*';
    }
    for (; str[end] != '\0' ; nb++, end++)
        new_string[nb] = str[end];
    new_string[nb] = '\0';
    return new_string;
}

/* This function calculates the content between the open parenthesis
   located at the start pointer, up to the  closing parentesis
   located at the end pointer. */

char *calc_parentheses(char *result, char *str, int start, int end)
{
    int tmp;

    result = realloc(result, strlen(end - start) + 2);
    for (tmp = 0; start < end; tmp++, start++)
        result[tmp] = str[start];
    result[tmp] = '\0';
    for (int i = 0; result[i] != '\0'; i++)
        if (result[i] > '9' || result[i] < '0') {
            result = eval_expr(result);
            i = 0;
        }
    if (str[end + 1] >= '0' && str[end + 1] <= '9') {
        result[tmp] = '*';
        result [tmp + 1] = '\0';
        }
    return result;
}

/* This function is a loop which will stop only when there are no more
   parentheses. This is the function that calls the other functions dealing
   with parentheses. */

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
            if ((result = malloc(end - start)) == NULL)
                malloc_error_message("parentheses_loop");
            result = calc_parentheses(result, str, start + 1, end);
            new_string = recup_str_before_parentheses(str, start);
            result = my_strcat(new_string, result);
            result = my_strcat(result, end_of_str(str, end + 1));
            str = result;
            puts(str);
        }
    return result;
}

/* This function checks if there is at least one perenthesis in the string
   sent as an argument. */

int check_parentheses(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '(' ||str[i] == ')')
            return 1;
    return 0;
}

/* This function checks if there are as many opening and closing parentheses. */

int check_nb_of_parentheses(char *str)
{
    int count = 0;
    int order = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '(')
            count++;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ')')
            count--;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            order++;
        if (str[i] == ')')
            order--;
        if (order < 0)
            return order;
    }
    return count;
}

char *parentheses(char *str)
{
    int count = 0;
    char *result = str;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            count++;
    }
    if (check_nb_of_parentheses(str) != 0) {
        printf("Syntax Error: check the number and order of parentheses.\n");
        exit(-1);
    }
    if (count == 0)
        return str;
    while (check_parentheses(result) != 0)
        result = parentheses_loop(result);
    return result;
}
