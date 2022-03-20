/*
** EPITECH PROJECT, 2022
** MY_CREATE_ENNEMIES_C
** File description:
** my_create_ennemies
*/

#include "my_defender.h"

void my_create_ennemies(game_t *game)
{
    float time = 1 / (((float)game->wave->wave_max / 10) + 1);
    if (game->wave->wave < game->wave->wave_max) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(game->wave->time))
            >= time) {
            sfClock_restart(game->wave->time);
            game->wave->count += 1;
        }
        if (game->wave->count > game->wave->wave) {
            game->wave->entity = my_append_entity(game);
            game->wave->wave += 1;
        }
    }
    if (game->wave->wave == game->wave->wave_max && game->wave->entity
        == NULL) {
        game->wave->wave = 0;
        game->wave->count = 0;
        game->wave->wave_max += 5;
        game->wave->wave_max % 10 != 0 ? game->wave->spd += 1 : 0;
        sfClock_restart(game->wave->time);
    }
}
