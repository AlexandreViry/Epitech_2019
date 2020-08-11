/*
** EPITECH PROJECT, 2019
** match.c
** File description:
** compare two strings and return 1 if they match
*/
#include<unistd.h>
#include<stdio.h>

int star_case (char const *s1, char const *s2)
{
    int a = 0;
    int b = 0;
    
    while (s1[a] == s2[b] && s1[a] != '\0' && s2[b] != '\0') {
        a++;
        b++;
        
        while (s2[b] == '*' || s2[b] != '\0') {
            b++;
        }
        while (s1[a] != s2[b]) {
            a++;
            if (s1[a] == '\0' && s2[b] != '\0') {
                return (0);
            }
            while (s2[b] == '*' || s2[b] != '\0') {
                b++;
            }
            while (s1[a] != s2[b]) {
                a++;
            }
        }
    }
    return (1);
}

int match(char const *s1, char const *s2) {
    {
        int i = 0;
        
        while (s1[i] != '\0') {
            i++;
            if (s1[i] != s2[i]) {
                if (s2[i] == '*') {
                    int j = star_case(s1, s2);
                    return (j);
                }
                else {
                    return(0);
                }
            }
        }
        return (1);
    }
}
