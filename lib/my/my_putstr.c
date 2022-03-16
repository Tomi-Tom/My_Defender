/*
** EPITECH PROJECT, 2021
** MY_PUTSTR_C
** File description:
** do a putstr
*/

#include "my.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
