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

int is_valid_string(char *str)
{
    char c;

    if (str[0] == '+' || str[0] == '*' || str[0] == '/' || str[0] == '%')
        return 1;
    c = str[strlen(str) - 1];
    if (c == '+' || c == '*' || c == '/' || c == '%' || c == '-')
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        c = str[i];
        if (c != '-' && c != '+' && c != '*' && c != '/' && c != '%'
            && c != '(' && c != ')' && (c > '9' || c < '0') && c != '\0') {
            printf("Syntax Error: only integers and");
            printf(" basic operators are allowed.\n");
            return 1;
        }
        if (str[0] == '\0')
            return 1;
    }
    return 0;
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
