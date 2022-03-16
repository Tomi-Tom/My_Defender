/*
** EPITECH PROJECT, 2021
** MY_SORT_INT_ARRAY_C
** File description:
** on tri des int par ordre croissant
*/

void my_swap(int *a, int *b);

int my_norme_filler(int *array, int i, int err)
{
    if (array[i] > array[i + 1]) {
        my_swap(&array[i], &array[i + 1]);
        err++;
    }
    return (err);
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int err = 1;

    while (err != 0) {
        err = 0;
        while (i < size - 1 ) {
            err = my_norme_filler(array, i, err);
            i++;
        }
        i = 0;
    }
}
