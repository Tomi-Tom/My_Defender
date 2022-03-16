/*
** EPITECH PROJECT, 2021
** MY_PUT_NBR_LL_C
** File description:
** putnbr with long long
*/

void my_putchar(char c);

void my_put_nbr_l(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            my_putchar('2');
            nb = -147483648;
        }
        nb = nb * (-1);
    }
    if (nb >= 10) {
        my_put_nbr_l(nb / 10);
        my_putchar(48 + (nb % 10));
    }
    if (nb < 10)
        my_putchar(48 + nb);
}
