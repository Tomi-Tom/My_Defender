/*
** EPITECH PROJECT, 2021
** MY_SWAP_C
** File description:
** do a swap of int pointed
*/

void my_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
