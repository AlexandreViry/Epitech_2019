/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** allocate memories and copies.
*/
char *my_strdup(char const *src) {
    char *str;
    int i = 0;
    
    while (src[i] != '\0')
    {
        i = i + 1;
    }
    str = malloc(sizeof(char) * i);
    i = 0;
    while (src[i] != '\0')
    {
        str[i]=src[i];
        i = i + 1;
    }
    str[i]='\0';
    return(str);
}
