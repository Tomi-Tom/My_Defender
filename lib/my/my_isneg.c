/*
** EPITECH PROJECT, 2021
** MY_ISNEG_C
** File description:
** that displays N is negative or P if positive or null.
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    if (n >= 0)
        my_putchar('P');
    return (0);
}
