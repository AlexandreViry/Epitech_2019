/*
** EPITECH PROJECT, 2019
** module
** File description:
** a
*/
int number(char **str);
int number2(char **str);
char *my_strtol(char **);
int my_strlen(char *str);

int modulo(char **str)
{
    char *str2 = *str;
    int results = number(&str2);
    str2 = my_strtol(&str2);
    int y = 1;

    while (y != 0) {
        results = results % number(&str2);
        str2 = my_strtol(&str2);
        y = number(&str2);
    }
    return (results);
}
