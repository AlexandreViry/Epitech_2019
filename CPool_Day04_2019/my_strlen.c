/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
**
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

int main(void)
{
    int i = 0;

    i = my_strlen("coucou toi");
    //@ assert i == 10;
    i = my_strlen("segfault");
    //@ assert i == 8;
    i = my_strlen("");
    //@ assert i == 0;
    return 0;
}
