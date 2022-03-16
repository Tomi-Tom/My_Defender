/*
** EPITECH PROJECT, 2021
** STRCAT
** File description:
** STRCAT
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i])
        i++;
    while (src[j]) {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return (dest);
}
