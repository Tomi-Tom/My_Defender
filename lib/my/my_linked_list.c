/*
** EPITECH PROJECT, 2021
** OPERATION_C
** File description:
** functions for operations
*/

#include "my.h"

lis_t *init_elem(int nb)
{
    lis_t *elem = malloc(sizeof(lis_t));

    elem->nb = nb;
    elem->next = NULL;
    return elem;
}

void append_elem(lis_t *first, int nb)
{
    lis_t *add = init_elem(nb);

    while (first->next != NULL) {
        first = first->next;
    }
    first->next = add;
}

void print_ll(lis_t *l)
{
    while (l != NULL) {
        my_put_nbr(l->nb);
        my_putchar('|');
        l = l->next;
    }
}

int len_list(lis_t *l)
{
    int i = 0;

    while (l->next != NULL) {
        l = l->next;
        i++;
    }
    return i + 1;
}

int list_is_sorted(lis_t *l)
{
    while (l->next != NULL) {
        if (l->nb > l->next->nb)
            return 0;
        l = l->next;
    }
    return 1;
}
