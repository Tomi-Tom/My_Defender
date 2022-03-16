/*
** EPITECH PROJECT, 2022
** MY_PARSE_PATH_C
** File description:
** my_parse_path
*/

#include "my_defender.h"

vec_t get_departure(char **map)
{
    vec_t vec;
    vec_t res;

    vec.x = 0;
    vec.y = 0;
    res.x = 0;
    res.y = 0;
    while (map[vec.y]) {
        vec.x = 0;
        while (map[vec.y][vec.x]) {
            map[vec.y][vec.x] == 'D' ? res = vec : res;
            vec.x++;
        }
        vec.y++;
    }
    return res;
}

char *my_get_path(char **map, vec_t pos, int lim, char *path)
{
    vec_t tmp;
    if (lim != 3 && map[pos.y - 1][pos.x] == '1') {
        tmp.x = pos.x;
        tmp.y = pos.y - 1;
        return my_strcat(my_get_path(map, tmp, 1, path), "U");
    } else if (lim != 4 && map[pos.y][pos.x + 1] == '1') {
        tmp.x = pos.x + 1;
        tmp.y = pos.y;
        return my_strcat(my_get_path(map, tmp, 2, path), "R");
    } else if (lim != 1 && map[pos.y + 1][pos.x] == '1') {
        tmp.x = pos.x;
        tmp.y = pos.y + 1;
        return my_strcat(my_get_path(map, tmp, 3, path), "D");
    } else if (lim != 2 && map[pos.y][pos.x - 1] == '1') {
        tmp.x = pos.x - 1;
        tmp.y = pos.y;
        return my_strcat(my_get_path(map, tmp, 4, path), "L");
    }
    path[0] = '\0';
    return path;
}

int my_len_path(char **map)
{
    int count = 0;
    int i = 0;
    int j = 0;

    while (map[i]) {
        j = 0;
        while (map[i][j]) {
            map[i][j] == '1' ? count = count + 1 : count;
            j++;
        }
        i++;
    }
    return count;
}

char *my_parse_path(char **map)
{
    vec_t vec = get_departure(map);
    int len_path = my_len_path(map);
    char *path = malloc(sizeof(char) * (len_path + 1));

    if (path == NULL)
        return NULL;
    path[0] = '\0';
    my_get_path(map, vec, 0, path);
    return my_revstr(path);
}
