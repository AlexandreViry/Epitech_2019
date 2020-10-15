#include "include/my.h"

char **malloc_array(char *init, int count, int len)
{
    char **result;
    int tmp = 0;
    int tmp2 = 0;

    for (int i = 0; i < len; i++) {
        if (init[i] >= '0' && init[i] <= '9' && init[i] != '\0') {
            while (init[i] >= '0' && init[i] <= '9' && init[i] != '\0')
                i++;
            count++;
        }
        if ((init[i] < '0' || init[i] > '9') && init[i] != '\0') {
            while ((init[i] < '0' || init[i] > '9') && init[i] != '\0')
                i++;
            count++;
            i--;
        }
    }
    if ((result = malloc(sizeof(char *) * (count + 1))) == NULL)
        malloc_error_message("malloc_array");
    for (int i = 0; i < count; i++) {
        if ((init[tmp] >= '0' || init[tmp] <= '9') && init[tmp] != '\0')
            for (tmp2 = 0; (init[tmp] > 47 || init[tmp] < 58) &&
                     init[tmp] != '\0'; tmp2++, tmp++);
        if ((init[tmp] < '0' || init[tmp] > '9') && init[tmp] != '\0')
            for (tmp2 = 0; (init[tmp] < 48 || init[tmp] > 57) &&
                     init[tmp] != '\0'; tmp2++, tmp++);
        if ((result[i] = malloc(tmp2 + 1)) == NULL)
            malloc_error_message("malloc_array");
    }
    return result;
}

char **fill_array(char **result, char *init, int count, int len)
{
    int tmp = 0;
    int tmp2 = 0;

    for (int i = 0; i < len; i++) {
        if (init[i] >= '0' && init[i] <= '9' && init[i] != '\0') {
            while (init[i] >= '0' && init[i] <= '9' && init[i] != '\0')
                i++;
            count++;
        }
        if ((init[i] < '0' || init[i] > '9') && init[i] != '\0') {
            while ((init[i] < '0' || init[i] > '9') && init[i] != '\0')
                i++;
            count++;
            i--;
        }
    }
    for (int i = 0; i < count; i++) {
        if (init[tmp] >= '0' && init[tmp] <= '9' && init[tmp] != '\0') {
            for (tmp2 = 0; init[tmp] > 47 && init[tmp] < 58 &&
                    init[tmp] != '\0'; tmp2++, tmp++)
                result[i][tmp2] = init[tmp];
            result[i][tmp2] = '\0';
            i++;
        }
        if ((init[tmp] < '0' || init[tmp] > '9') && init[tmp] != '\0') {
            for (tmp2 = 0; (init[tmp] < 48 || init[tmp] > 57) &&
                    init[tmp] != '\0'; tmp2++, tmp++)
                result[i][tmp2] = init[tmp];
            result[i][tmp2] = '\0';
        }
    }
    result[count] = NULL;
    return result;
}

char **my_str_to_word_array(char *init)
{
    char **result = malloc_array(init, 0, strlen(init));

    result = fill_array(result, init, 0, strlen(init));
    if (result == 0)
        exit(-1);
    return result;
}
