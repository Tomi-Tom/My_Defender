/*
** EPITECH PROJECT, 2021
** MY_STRLEN_C
** File description:
** do a my_strlen
*/

#include "my.h"

int my_arr_len(char **array)
{
    int i = 0;

    if (array == NULL)
        return 0;
    while (array[i])
        i++;
    return i;
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}
