#include "include/my.h"

int main(int ac, char **av)
{
    int value1;
    int value2;
    char *result;

    if (ac != 3)
        return -1;
    value1 = strlen(av[1]);
    value2 = strlen(av[2]);
    if (value1 <= value2)
        result = infin_add(av[2], av[1], value2);
    else
        result = infin_add(av[1], av[2], value1);
    printf("%s\n", result);
    return 0;
}
