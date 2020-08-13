#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat_params(int argc, char **argv)
{
    int len = 0;
    char *res;
    int tmp;

    for (int count = 1; count < argc; ++count, ++len)
        len = len + strlen(argv[count]) + 1;
    res = malloc(len + 1);
    len = 0;
    for (int count = 1; count < argc; ++count) {
        for (tmp = 0; argv[count][tmp] != '\0'; tmp++, len++)
            res[len] = argv[count][tmp];
        res[len] = '\n';
        len++;
    }
    res[len] = '\0';
    return res;
}

int main(int ac, char **av)
{
    printf("%s", concat_params(ac, av));
    return 0;
}
