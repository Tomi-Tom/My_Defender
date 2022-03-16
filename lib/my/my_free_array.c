/*
** EPITECH PROJECT, 2022
** MY_FREE_ARRAY_C
** File description:
** my_free_array
*/

#include "my.h"

void my_free_array(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        free(array[i++]);
    free(array);
}