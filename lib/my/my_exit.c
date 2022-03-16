/*
** EPITECH PROJECT, 2022
** MY_EXIT_C
** File description:
** my_exit
*/

#include "my.h"

void my_exit(char *exit_message, int exit_code)
{
    my_putstr(exit_message);
    exit(exit_code);
}
