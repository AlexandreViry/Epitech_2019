#include "../include/my.h"

char *concat_strings(int ac, char **av)
{
    char *result = malloc(strlen(av[1]) + 1);

    strcpy(result, av[1]);
    for (int i = 2; i < ac; i++)
        result = my_strcat(result, av[i]);
    return result;
}

char *analyse_string(char *str)
{
    char c;

    for (int i = 0; str[i] != '\0'; i++) {
        c = str[i];
        if (c != '-' && c != '+' && c != '*' && c != '/' && c != '%'
            && c != '(' && c != ')' && (c > '9' || c < '0') && c != '\0') {
            printf("Syntax Error.\n");
            return NULL;
        }
    }
    return str;
}