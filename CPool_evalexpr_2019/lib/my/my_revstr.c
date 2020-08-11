/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** 
*/

char *my_revstr(char *str)
{
    int x = 0;
    int y = 0;
    int z = 0;
    char *stm = str;
    char stf;

    while (str[x] != '\0') {
        x = x + 1;
    }
    x = x - 1;
    z = x / 2;
    while (x > z) {
        stf = stm[y];
        str[y] = stm[x];
        str[x] = stf;
        y = y + 1;
        x = x - 1;
    }
    return (str);
}
    
