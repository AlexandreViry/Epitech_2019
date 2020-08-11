/*
** EPITECH PROJECT, 2019
** getmin
** File description:
** minimal number
*/

int get_min(char **str,int x)
{
    char *str2 = *str;
    x = x - 1;
    int y = str2[x];
    int f = str2[x + 1];

    while (y >= 48 && y <= 57 ||y == f) {
        x = x - 1;
        y = str2[x];
    }
    return (x);
}
