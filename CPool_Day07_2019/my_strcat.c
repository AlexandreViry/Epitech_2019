/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** function that contatenate two strings
*/

char *my_strcat (char *dest, char const *src) {

    int d = 0;
    
    while (src[d] != '\0') {
        d = d + 1;
    }
    int i = 0;
        
    while (dest[i] < '\0') {
        i = i + 1;
        char dest[d+i];
    }
    dest[i]=src[0];
    while (src[i] < '\0') {
        i = i+1;
        dest[i]=src[d];
    }
    return(dest);
}
