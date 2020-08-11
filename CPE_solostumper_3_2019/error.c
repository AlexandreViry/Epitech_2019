/*
** EPITECH PROJECT, 2020
** error
** File description:
** find potential errors
*/

int error(int ac, char **av)
{
    int a;
    int b;

    if (ac != 3)
        return (1);
    for (int i = 0; av[1][i] != '\0'; i++) {
        a = av[1][i];
        if (a < 48 && a != '-'|| a > 57 && a != '-')
            return (1);
    }
    for (int i = 0; av[2][i] != '\0'; i++) {
        b = av[2][i];
        if (b < 48 && b != '-'|| b > 57 &&b != '-')
            return (1);
    }
    return (0);
}
