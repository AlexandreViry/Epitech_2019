#include "include/my.h"

int main(void)
{
    int value1;
    int value2;
    char *result;

    value1 = strlen("13");
    value2 = strlen("139");
    if (value1 <= value2)
        result = infin_add("139", "13", value2);
    else
        result = infin_add("13", "139", value1);
    //@ assert strcmp(result, "152") == 0;
    return 0;
}
