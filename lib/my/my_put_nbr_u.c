/*
** EPITECH PROJECT, 2021
** MY_PUT_NBR_U_C
** File description:
** putnbr unsigned
*/

void my_putchar(char c);

void my_put_nbr_u(unsigned int nb)
{
    if (nb >= 10) {
        my_put_nbr_u(nb / 10);
        my_putchar(48 + (nb % 10));
    }
    if (nb < 10)
        my_putchar(48 + nb);
}
