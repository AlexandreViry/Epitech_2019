#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define ATN(c) (c - '0')
#define NTA(n) (n + '0')

char *my_revstr(char *str) {

    int len_str = 0;
    char *tmp;
    int y = 0;

    len_str = strlen(str);
    tmp = malloc(sizeof(char) * (len_str + 1));
    len_str--;
    for (; len_str >= 0; y++, len_str--)
        tmp[y] = str[len_str];
    tmp[y] = '\0';
    return tmp;
}

char *last_carry(char *result, int carry, int count)
{
    int i;
    int y;

    for (int i = 0; i != count; i++)
        result[i] = NTA(result[i]);
    if (carry > 0) {
        result[count] = NTA(carry);
        result[count + 1] = '\0';
    }
    else
        result[count] = '\0';
    result = my_revstr(result);
    for (i = 0; result[i] == '0' && result[i + 1] != '\0'; i++)
        if (result[i] == '\0')
            return result;
    for (y = 0; result[i] != '\0'; y++, i++)
        result[y] = result[i];
    result[y] = '\0';
    return result;
}

char *negative_carry(char *result, int carry, int count)
{
    int i;
    int y;

    if (carry > 0) {
        result[count] = result[count] - carry;
        result[count + 1] = '\0';
    }
    else
        result[count] = 0;
    for (int i = 0; i != count; i++)
        result[i] = NTA(result[i]);
    result = my_revstr(result);
    for (i = 0; result[i] == '0' && result[i + 1] != '\0'; i++)
        if (result[i] == '\0')
            return result;
    for (y = 0; result[i] != '\0'; y++, i++)
        result[y] = result[i];
    result[y] = '\0';
    return result;
}

char *subtractor(char *str, char *str2, char *result)
{
    int carry = 0;
    int count = 0;

    for (int i = 0; str2[i] != '\0' && str[i] != '\0'; i++, count = i) {
        result[i] = str[i] - (str2[i] + carry);
        carry = 0;
        if (result[i] < 0) {
            result[i] += 10;
            carry++;
        }
    }
    for (; str[count] != '\0'; count++) {
        result[count] = ATN(str[count]) - carry;
        carry = 0;
        if (result[count] < 0) {
            result[count] += 10;
            carry++;
        }
    }
    result[count] = '\0';
    return negative_carry(result, carry, count);
}

char *calculator(char *str, char *str2, char *result)
{
    int carry = 0;
    int count = 0;

    for (int i = 0; str2[i] != '\0'; i++, count = i) {
        result[i] = str[i] + str2[i] + carry - 96;
        carry = 0;
        if (result[i] > 9) {
            result[i] -= 10;
            carry++;
        }
    }
    for (; str[count] != '\0'; count++) {
        result[count] = ATN(str[count]) + carry;
        carry = 0;
        if (result[count] > 9) {
            result[count] -= 10;
            carry++;
        }
    }
    return last_carry(result, carry, count);
}

char *double_negative(char *str, char *str2, char *result)
{
    char *result2;
    int len;
    int i;

    str[strlen(str) - 1] = '\0';
    str2[strlen(str2) - 1] = '\0';
    result = calculator(str, str2, result);
    len = strlen(result);
    result2 = malloc(len + 2);
    result2[0] = '-';
    for (i = 1; result[i] != '\0'; i++)
        result2[i] = result[i - 1];
    result2[i] = result[i - 1];
    result2[len + 1] = '\0';
    return result2;
}

int who_is_bigger(char *str, char *str2)
{
    if (strlen(str) == strlen(str2))
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] < str2[i])
                return 2;
            if (str[i] > str2[i])
                return 1;
        }
    if (strlen(str) > strlen(str2))
        return 1;
    return 2;
}

char *change_sign(char *result)
{
    char *res = malloc(strlen(result) + 2);
    int i;

    res[0] = '-';
    for (i = 0; result[i] != '\0'; i++)
        res[i + 1] = result[i];
    res[i + 1] = '\0';
    free(result);
    return res;
}

char *negative(char *str, char *str2, char *result)
{
    if (str[strlen(str) - 1] == '-') {
        str[strlen(str) - 1] = '\0';
        if (who_is_bigger(str, str2) == 1) {
            result = subtractor(str2, str, result);
            result = change_sign(result);
        }
        if (who_is_bigger(str, str2) == 2)
            result = subtractor(str, str2, result);
    } else {
        str2[strlen(str2) - 1] = '\0';
        if (who_is_bigger(str, str2) == 1)
            result = subtractor(str, str2, result);
        if (who_is_bigger(str, str2) == 2)
            result = subtractor(str2, str, result);
    }
    return result;
}
char *func_call(char *str, char *str2, int len)
{
    char *result = malloc(len + 2);

    str = my_revstr(str);
    str2 = my_revstr(str2);
    if (str2[strlen(str2) - 1] == '-' && str[strlen(str) - 1] == '-')
        return double_negative(str, str2, result);
    else if (str2[strlen(str2) - 1] == '-' || str[strlen(str) - 1] == '-')
        return negative(str, str2, result);
    result = calculator(str, str2, result);
    return result;
}

char *infin_add(char *str, char *str2)
{
    int value1;
    int value2;
    char *result;

    value1 = strlen(str);
    value2 = strlen(str2);
    if (value1 <= value2)
        result = func_call(str2, str, value2);
    else
        result = func_call(str, str2, value1);
    return result;
}

int my_compute_power_it(int nb , int p)
{
    int res = nb;
    int tmp = p;

    if (tmp < 0)
        return 0;
    if (tmp == 0)
        return 1;
    for (; tmp > 1; tmp--) {
        if (INT_MAX / res <= nb && INT_MAX / res > 0)
            return 0;
        res = nb * res;
    }
    return res;
}

char *multiplier(char *str, char *str2, char *result)
{
    int i;
    char *tmp = "0";
    for (i = 0; str2[i] != '\0'; i++) {
        for (int y = (str2[i] - 48) * my_compute_power_it(10, i); y > 0; y--) {
            result = infin_add(tmp, my_revstr(str));
            tmp = result;
        }
    }
    free(str);
    free(str2);
    return result;
}

char *negative_to_positive(char *str, char *str2, char *result)
{
    str[strlen(str) - 1] = '\0';
    str2[strlen(str2) - 1] = '\0';

    return multiplier(str, str2, result);
}

char *negative_product(char *str, char *str2, char *result)
{
    char *new_result;
    int tmp = 1;

    if (str[strlen(str) - 1] == '\0')
        str[strlen(str) - 1] = '\0';
    if (str2[strlen(str2) - 1] == '\0')
        str2[strlen(str2) - 1] = '\0';
    result = multiplier(str, str2, result);
    return result;
}

char *func_caller(char *str, char *str2, int len)
{
    char *result = malloc(len + 2);

    str = my_revstr(str);
    str2 = my_revstr(str2);
    if (str[strlen(str) - 1] == '-' && str2[strlen(str2) - 1] == '-')
        return (negative_to_positive(str, str2, result));
    if (str[strlen(str) - 1] == '-' || str2[strlen(str2) - 1] == '-')
        return (negative_product(str, str2, result));
    result = multiplier(str, str2, result);
    return result;
}

char *infin_mult(char *str, char *str2)
{
    int value1;
    char *result;

    value1 = strlen(str) + strlen(str2);
    if (strlen(str) <= strlen(str2))
        result = func_caller(str2, str, value1);
    else
        result = func_caller(str, str2, value1);
    return result;
}

char *sub_negative(char *str, char *str2, char *result)
{
    char *result2;
    int len;
    int i;

    result = calculator(str, str2, result);
    len = strlen(result);
    result2 = malloc(len + 2);
    result2[0] = '-';
    for (i = 1; result[i] != '\0'; i++)
        result2[i] = result[i - 1];
    result2[i] = result[i - 1];
    result2[len + 1] = '\0';
    return result2;
}


char *sub_func_call(char *str, char *str2, int len)
{
    char *result = malloc(len + 2);

    str = my_revstr(str);
    str2 = my_revstr(str2);
    if (str2[strlen(str2) - 1] == '-' && str[strlen(str) - 1] != '-') {
        str2[strlen(str2) -1] = '\0';
        return infin_add(my_revstr(str), my_revstr(str2));
    }
    if (str2[strlen(str2) - 1] != '-' && str[strlen(str) - 1] != '-')
        return subtractor(str, str2, result);
    if (str2[strlen(str2) - 1] != '-' && str[strlen(str) - 1] == '-') {
        str[strlen(str) - 1] = '\0';
        return sub_negative(str, str2, result);
    }
    if (str2[strlen(str2) - 1] == '-' && str[strlen(str) - 1] == '-') {
        str2[strlen(str2) -1] = '\0';
        str[strlen(str) -1] = '\0';
        return subtractor(str, str2, result);
    }
    return str;
}

char *infin_sub(char *str, char *str2)
{
    int value1;
    int value2;
    char *result;

    value1 = strlen(str);
    value2 = strlen(str2);
    if (value1 <= value2)
        result = sub_func_call(str2, str, value2);
    else
        result = sub_func_call(str, str2, value1);
    return result;
}

int main(void)
{
    int res;
    char *result;

    result = infin_sub("0", "0");
    res = strcmp(result, "0");
    //@ assert res == 0;
    result = infin_sub("-950", "-5000");
    res = strcmp(result, "4050");
    //@ assert res == 0;
    result = infin_sub("-760", "900");
    res = strcmp(result, "-1660");
    //@ assert res == 0;
    result = infin_sub("8524", "5846");
    res = strcmp(result, "2678");
    //@ assert res == 0;
    result = infin_sub("7854", "25");
    res = strcmp(result, "7829");
    //@ assert res == 0;
    return 0;
}
