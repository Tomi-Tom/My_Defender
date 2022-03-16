/*
** EPITECH PROJECT, 2022
** MY_HELP_C
** File description:
** my_help
*/

#include "my.h"

int my_help(void)
{
    my_putstr("\t\t\n+-----------------------------------+\n");
    my_putstr("\t\t|   O=   -   -   -   -   -   -   X  |\n");
    my_putstr("\t\t| .      .   MY_DEFENDER  .    *    |\n");
    my_putstr("\t\t|     *      .      .        .     .|\n");
    my_putstr("\t\t|  000 000 000 000 000 000 000 000  |\n");
    my_putstr("\t\t| .  000 000 000 000 000 000 000  . |\n");
    my_putstr("\t\t+-----------------------------------+\n");
    my_putstr("\nUSAGE :\n\n\t\t./my_defender [MAP]\n\n");
    my_putstr("\nDESCIRPTION :\n\n\t\t[MAP]\ta file that");
    my_putstr(" contain a valid map composed with\n\t\t");
    my_putstr("\t0, 1, 2, and B\n\n\nvalid map :\n\n");
    my_putstr("000000000000000\n022202220222000\n21112111");
    my_putstr("2111212\n212121212121212\n212121212121212\n");
    my_putstr("212111211121112\n000222022202220\n000000000000000\n");
    return 0;
}
