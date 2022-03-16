/*
** EPITECH PROJECT, 2021
** PUTNBR_BASE
** File description:
** PUTNBR BASE
*/

void my_putchar(char c);

int my_strlen_base(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

int my_put_nbr_base(int nbr, char const *base)
{
    int len = my_strlen_base(base);

    if (nbr >= len) {
        my_put_nbr_base(nbr / len, base);
        my_putchar(base[nbr % len]);
    }
    if (nbr < len)
        my_putchar(base[nbr]);
    return (0);
}
