/*
** EPITECH PROJECT, 2021
** EXEMPLE_C
** File description:
** exemple_c
*/

#include "my.h"

int my_error_handling(int ac, char **av)
{
    int fd = 0;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return 0;
    if (ac > 2)
        return my_puterror("Error : Too much arguments\nPlease check -h\n");
    if (ac < 2)
        return my_puterror("Error : Not enough arguments\nPlease check -h\n");
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return my_puterror("Error : file not found\nPlease check -h\n");
    close(fd);
    return 0;
}
