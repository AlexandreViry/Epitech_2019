/*
** EPITECH PROJECT, 2019
** match.c
** File description:
** compare two strings and return 1 if they match
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int star_case (char const *s1, char const *s2)
{
    int a = 0;
    int b;

    for (b = 0; s1[a] == s2[b] && s1[a] != '\0' && s2[b] != '\0'; a++, b++);
    b++;
    for (; s1[a] != s2[b] && s1[a] != '\0' && s2[b] != '\0'; a++);
    if (s1[a] != s1[b] && s1[a] == '\0' && s2[b] != '\0')
        return 0;
    return 1;
}

int match(char const *s1, char const *s2)
{
    int len = strlen(s1);
    int i;

    for (i = 0; i <= len; i++) {
        if (s1[i] != s2[i] && s2[i] == '*')
                return star_case(s1, s2);
        if (s1[i] != s2[i] && s2[i] != '*')
            return 0;
    }
    return (1);
}

int main(void)
{
    int res;

    res = match("salut", "salut");
    //@ assert res == 1;
    res = match("salut", "salutations");
    //@ assert res == 0;
    res = match("", "coucou");
    //@ assert res == 0;
    res = match("salut", "*t");
    //@ assert res == 1;
    res = match("salut", "*z");
    printf("%d\n", res);
    //@ assert res == 0;
    return 0;
}
