#include<unistd.h>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>

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
        result[count] = NTA(1);
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
            result = subtractor(str, str2, result);
            result = change_sign(result);
        }
        if (who_is_bigger(str, str2) == 2)
            result = subtractor(str2, str, result);
    } else {
        str2[strlen(str2) - 1] = '\0';
        if (who_is_bigger(str, str2) == 1)
            result = subtractor(str, str2, result);
        if (who_is_bigger(str, str2) == 2)
            result = subtractor(str2, str, result);
    }
    return result;
}

char *infin_add(char *str, char *str2, int len)
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
int main(void)
{
    int res;
    int value1;
    int value2;
    char *result;

    value1 = strlen("13");
    value2 = strlen("139");
    if (value1 <= value2)
        result = infin_add("139", "13", value2);
    else
        result = infin_add("13", "139", value1);
    res = strcmp(result, "152");
    //@ assert res == 0;
    printf("%s\n", result);

    value1 = strlen("-100");
    value2 = strlen("100");
    if (value1 <= value2)
        result = infin_add("100", "-100", value2);
    else
        result = infin_add("-100", "100", value1);
    res = strcmp(result, "0");
    //@ assert res == 0;
    printf("%s\n", result);

    value1 = strlen("-13");
    value2 = strlen("-139");
    if (value1 <= value2)
        result = infin_add("-139", "-13", value2);
    else
        result = infin_add("-13", "-139", value1);
    res = strcmp(result, "-152");
    //@ assert res == 0;
    printf("%s\n", result);

    value1 = strlen("9");
    value2 = strlen("1");
    if (value1 <= value2)
        result = infin_add("9", "1", value2);
    else
        result = infin_add("1", "9", value1);
    res = strcmp(result, "10");
    //@ assert res == 0;
    printf("%s\n", result);

    value1 = strlen("9999999998");
    value2 = strlen("1");
    if (value1 <= value2)
        result = infin_add("1", "9999999998", value2);
    else
        result = infin_add("9999999998", "1", value1);
    res = strcmp(result, "9999999999");
    //@ assert res == 0;
    printf("%s\n", result);
    return 0;
}
