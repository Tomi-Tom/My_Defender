/*
** EPITECH PROJECT, 2022
** MY_PRINT_TAB_C
** File description:
** my_print_tab
*/

#include "my.h"

void my_putarray(char **tab)
{
    if (tab == NULL)
        return;
    while (*tab) {
        my_putstr(*(tab++));
        my_putchar('\n');
    }
}
