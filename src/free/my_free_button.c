/*
** EPITECH PROJECT, 2022
** MY_FREE_BUTTON_C
** File description:
** my_free_button
*/

#include "my_defender.h"

void my_free_button(button_t *button)
{
    sfSprite_destroy(button->sprite);
    free(button);
}
