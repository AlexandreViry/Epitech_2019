#include "include/my.h"

char *calc_modulo(char *nb1, char *nb2, char *result)
{
    char *init = nb1;
    char *rest;
    char *tmp;

    while (strcmp(nb1, "0") != 0 && compare_size(nb1, nb2) == 1 && strcmp
           (infin_mult(result, nb2), init) != 0)
    {
        tmp = divide_string(nb1, nb2);
        result = infin_add(infin_mult(result, "10"), sub_loop(tmp, nb2));
        rest = sub_loop2(tmp, nb2);
        nb1 = recup_string(nb1, nb2);
        if (nb1[0] != '0' || nb1[1] == '\0') {
            rest = infin_mult(rest, power_of_ten(strlen(nb1)));
            nb1 = infin_add(nb1, rest);
        }
        result = if_zero(result, nb1, nb2, init);
    }
    return nb1;
}

char *modulo_negativity(char *str, char *str2)
{
    if (str[0] == '-' && str2[0] == '-')
        return calc_modulo(negative_to_positive2(str),
                           negative_to_positive2(str2), "0");
    if (str[0] == '-' && str2[0] != '-')
        return change_sign(calc_modulo(negative_to_positive2(str), str2, "0"));
    if (str[0] != '-' && str2[0] == '-')
        return change_sign(calc_modulo(str, negative_to_positive2(str2), "0"));
    return str;
}

char *infin_mod(char *str, char *str2)
{
    char *result;

    if (strcmp(str, "0") == 0)
        return "0";
    if (strcmp(str2, "0") == 0) {
        printf("Error: divisions by 0 are prohibited.\n");
        exit(84);
    }
    if (strcmp(str, str2) == 0)
        return "1";
    if (str[0] == '-' || str2[0] == '-')
        return modulo_negativity(str, str2);
    if (strlen(str2) > strlen(str))
        return "0";
    result = calc_modulo(str, str2, "0");
    return result;
}
