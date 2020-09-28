#include "include/my.h"

void map_without_size(map_t **map)
{
    char *tmp = malloc(strlen((*map)->map) + 1);
    int len = strlen((*map)->map);
    int count;
    char *tmp2;

    strcpy(tmp, (*map)->map);
    for (count = 0; (*map)->map[count] != '\n'; count++);
    count++;
    tmp2 = malloc(count + 1);
    for (int i = 0; tmp[i] != '\n'; i++)
        tmp2[i] = tmp[i];
    tmp2[count - 1] = '\0';
    (*map)->size_height = atoi(tmp2);
    free(tmp2);
    len = len - count;
    (*map)->map = malloc(len + 1);
    for (int i = 0; tmp[count] != '\0'; count++, i++)
        (*map)->map[i] = tmp[count];
    (*map)->map[len - 1] = '\0';
}

void fill_map(map_t **map)
{
    int x = 0;
    int y = 0;

    for (int i = 0; (*map)->map[i] != '\0'; i++, y++) {
        if ((*map)->map[i] == '\n') {
            (*map)->size_length = y;
            x++;
            y = -1;
            continue;
        }
        if ((*map)->map[i] == '.')
            (*map)->map_int[x][y] = 1;
        if ((*map)->map[i] == 'o')
            (*map)->map_int[x][y] = 0;
    }
}

void check_buff(char *buff)
{
    for (int i = 3; buff[i] != '\0'; i++)
        if (buff[i] != '\n' && buff[i] != 'o' && buff[i] != '.')
            exit(84);
}

void init_map(char **filepath, map_t *map)
{
    struct stat sb;
    int fd = open(filepath[1], O_RDONLY);
    int count = 0;
    char **tmp;

    if (fd < 0)
        exit(84);
    fstat(fd, &sb);
    map->map = malloc(sizeof(char) * (int)sb.st_size + 1);
    if (read(fd, map->map, sb.st_size) == -1)
        exit(84);
    check_buff(map->map);
    map->map[sb.st_size] = '\0';
    map_without_size(&map);
    close(fd);
    for (int i = 0; map->map[i] != '\0'; i++)
        if (map->map[i] == '\n')
            count++;
    map->map_int = malloc(sizeof(int *) * (count + 1));
    tmp = my_str_to_word_array(map->map, '\n');
    for (count = 0; tmp[count] != NULL; count++) {
        map->map_int[count] = malloc(sizeof(int) * (strlen(tmp[count]) + 1));
    }
    fill_map(&map);
}
