/*
** EPITECH PROJECT, 2022
** MY_INIT_ENNEMIES_C
** File description:
** my_init_ennemies
*/

#include "my_defender.h"

void my_init_ennemies(game_t *game)
{
    sfTexture *texture = sfTexture_createFromFile("assets/ennemi_sheet.png",
        NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    game->wave->time = sfClock_create();
    game->wave->begin = get_departure(game->map);
    game->wave->entity = NULL;
    game->wave->count = 0;
    game->wave->wave = 0;
    game->wave->wave_max = 5;
    game->wave->sprite = sprite;
    return;
}