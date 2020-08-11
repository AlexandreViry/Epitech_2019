/*
** EPITECH PROJECT, 2019
** number
** File description:
** a
*/

int number(char **str)
{
    int results = 0;
    int x = 0;
    int y = 0;
    char *str2 = *str;
    int z = 0;

    while(str2[x] != '\0') {
        y = str2[x];
        if (y < 48 || y > 57) 
            return (results);
        results = results + (y - 48);
        x = x + 1;
        z = str2[x];
        if (str2[x] != '\0' && z >= 48 && z <= 57)
            results = results * 10;
    }
    return (results);
}

