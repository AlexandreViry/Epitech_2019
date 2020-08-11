/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** We compare strings values
*/

int my_strcmp(char const *s1, char const *s2)
{
    int n = 0;
    int val_s1 = 0;
    int val_s2 = 0;
    int result;

    while (s1[n] != '\0' || s2[n] != '\0') {
        val_s1 = val_s1 + s1[n];
        val_s2 = val_s2 + s2[n];
        n++;
    }
    result = val_s2 - val_s1;
    return (result);
}
