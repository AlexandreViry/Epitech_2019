#include "include/my.h"

char *div_loop(char *str, char *str2)
{
    char *result = "0";
    char *tmp = infin_sub(str, str2);

    for (int i = 0; tmp[i] != '\0'; i++)
        for (int y = tmp[i] - 48; y > 0; y--) {
            str = infin_sub(str, str2);
            printf("char = %c\n", tmp[i]);
            result = infin_add(result, "1");
            //puts(result);
        }
    return result;
}

char *infin_div(char *str, char *str2)
{
    char *result;

    if (strcmp(str, "0") == 0)
        return "0";
    if (strcmp(str2, "0") == 0) {
        exit(84);
        puts("Error: divisions by 0 are prohibited");
    }
    if (strcmp(str, str2) == 0)
        return "1";
    result = div_loop(str, str2);
    return result;
}
