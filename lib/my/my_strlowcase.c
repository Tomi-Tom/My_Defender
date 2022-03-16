/*
** EPITECH PROJECT, 2021
** STRLOWCASE
** File description:
** STRLOWCASE
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        i++;
    }
    return (str);
}
