/*
** EPITECH PROJECT, 2021
** STRNCAT
** File description:
** STRNCAT
*/

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    int j = 0;

    while (dest[i])
        i++;
    while (src[j + 1] && j < n) {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j + 1] = '\0';
    return (dest);
}
