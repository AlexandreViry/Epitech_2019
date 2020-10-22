#include "../include/my.h"

char *concat_strings(int ac, char **av)
{
    char *result;

    if ((result = malloc(strlen(av[1]) + 1)) == NULL)
        malloc_error_message("concat_strings");
    strcpy(result, av[1]);
    for (int i = 2; i < ac; i++)
        result = my_strcat(result, av[i]);
    return result;
}

char *merge_successive_signs(char *str, int i, char sign)
{
    char *tmp = malloc(strlen(str) + 1);
    int y;

    strcpy(tmp, str);
    if ((str = realloc(str, strlen(str))) == NULL)
        malloc_error_message("merge_successive_signs");
    for (y = 0; y < i; y++)
        str[y] = tmp[y];
    if (sign != '+' || str[i - 1] != '(') {
        str[i] = sign;
        ++i;
        y = i + 1;
    }
    else
        y = i + 1;
    for (; tmp[y] != '\0'; y++, i++)
        str[i] = tmp[y];
    str[i] = '\0';
    free(tmp);
    return str;
}

char *search_two_signs(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if ((str[i] == '+' && str[i + 1] == '-') ||
            (str[i] == '-' && str[i + 1] == '+'))
            merge_successive_signs(str, i, '-');
        if ((str[i] == '-' && str[i + 1] == '-') ||
            (str[i] == '+' && str[i + 1] == '+'))
            merge_successive_signs(str, i, '+');
    }
    return str;
}

int check_for_negative_char(char *str)
{
    if (str[0] == '-' && str[1] != '(' && (str[1] > '9' || str[1] < '0'))
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            for (; str[i] == '-'; i++)
                if (str[i + 1] != '\0' && (str[i + 1] == '/' || str[i + 1] =='*'
                                           || str[i] == '%' || str[i] == '+'))
                    return 1;
        }
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+' || str[i] == '*' || str[i] == '%' || str[i] == '/' ||
            str[i] == '-')
            for (int y = i; str[y] == '+' || str[y] == '*' || str[y] == '%' ||
                     str[y] == '/' || str[y] == '-'; y++)
                if (y - i >= 3)
                    return 1;
    }
    return 0;
}

int is_valid_string(char *str)
{
    char c;

    if (str[0] == '+' || str[0] == '*' || str[0] == '/' || str[0] == '%' ||
        strlen(str) == 0)
        return 1;
    c = str[strlen(str) - 1];
    if ((c > '9' || c < '0') && c != ')')
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        c = str[i];
        if ((c == '(' && str[i + 1] == ')') ||
            (c != '-' && c != '+' && c != '*' && c != '/' && c != '%'
            && c != '(' && c != ')' && (c > '9' || c < '0') && c != '\0')) {
            printf("Syntax Error: only integers and");
            printf(" basic operators are allowed.\n");
            return 1;
        }
    }
    if (str[0] == '\0')
        return 1;
    return check_for_negative_char(str);
}

char **delete_useless_zero(char **str)
{
    int y;
    char *tmp;

    for (int i = 0; str[i] != NULL; i++)
        if (str[i][0] == '0') {
            for (y = 0; str[i][y] == '0' && str[i][y + 1] != '\0'; y++);
            tmp = my_revstr(str[i]);
            if ((str[i] = realloc(str[i], strlen(str[i]) - y + 1)) == NULL)
                malloc_error_message("delete_useless_zero");
            strncpy(str[i], tmp, strlen(tmp) - y);
            str[i][strlen(tmp) - y] = '\0';
            str[i] = my_revstr(str[i]);
        }
    return str;
}
