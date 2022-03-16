/*
** EPITECH PROJECT, 2022
** MY_ARRCAT_C
** File description:
** my_arrcat
*/

#include "my.h"

char **my_arrcat_width(char **dest, char **src)
{
    char **arr = malloc((my_arr_len(src) + 1) * sizeof(char *));
    char *tmp = NULL;
    int i = 0;

    while (src[i]) {
        tmp = malloc((my_strlen(dest[i]) + my_strlen(src[i]) + 1)
            * sizeof(char));
        if (tmp == NULL)
            return NULL;
        tmp[0] = '\0';
        my_strcat(tmp, dest[i]);
        my_strcat(tmp, src[i]);
        arr[i] = tmp;
        i++;
    }
    arr[i] = NULL;
    return arr;
}

char **my_arrcat_height(char **dest, char **src)
{
    char **arr = malloc((my_arr_len(dest) + my_arr_len(src) + 1)
        * sizeof(char *));
    int i = 0;
    int j = 0;

    if (arr == NULL)
        return NULL;
    while (dest && dest[i]) {
        arr[i] = my_strdup(dest[i]);
        i++;
    }
    while (src[j]) {
        arr[i + j] = my_strdup(src[j]);
        j++;
    }
    arr[i + j] = NULL;
    return arr;
}

char **my_arrcat(char **dest, char **src, int opt)
{
    char **arr = NULL;

    if (opt == 0)
        arr = my_arrcat_width(dest, src);
    if (opt == 1)
        arr = my_arrcat_height(dest, src);
    return arr;
}
