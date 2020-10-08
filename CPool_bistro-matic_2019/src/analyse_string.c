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
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        c = str[i];
        if (c != '-' && c != '+' && c != '*' && c != '/' && c != '%'
            && c != '(' && c != ')' && (c > '9' || c < '0') && c != '\0') {
            printf("Syntax Error: only integers and");
            printf(" basic operators are allowed.\n");
            return 1;
        }
    }
    return 0;
}
