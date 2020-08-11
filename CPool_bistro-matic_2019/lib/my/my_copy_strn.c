/*
** EPITECH PROJECT, 2019
** my_copy_strn.c
** File description:
** copie string from n
*/

char *my_copy_strn(char *str, int n)
{
    int count = 0;
    while (str[n] != '\0') {
        str[count] = str[n];
        count = count + 1;
        n = n + 1;
    }
    str[count] = '\0';
    return (str);
}
