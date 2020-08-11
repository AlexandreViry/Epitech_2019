/*
** EPITECH PROJECT, 2019
** difference
** File description:
** a
*/
int number(char **str);
int number2(char **str);
char *my_strtol(char **);
int my_strlen(char *str);

int difference(char **str)
{
    char *str2 = *str;
    int y = my_strlen(str2);
    int x = 0;
    int results = number(&str2);
    str2 = my_strtol(&str2);
    
    while (x < y) {
        results = results - number(&str2);
        x = x + number2(&str2);
        str2 = my_strtol(&str2);
        x = x + 1;
    }
    return (results);
}

