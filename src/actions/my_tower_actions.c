/*
** EPITECH PROJECT, 2022
** MY_TOWER_ACTIONS_C
** File description:
** my_tower_actions
*/

#include "my_defender.h"

float my_get_distance(tile_t *tile, vec_t vec)
{
    float res = 0;
    float x = tile->x * 128 - vec.x * 128;
    float y = tile->y * 128 - vec.y * 128;

    x < 0 ? x = -x : x;
    y < 0 ? y = -y : y;
    res = sqrt((square(x) + square(y)));
    return res;
}

void my_tower_in_tile_attack(tile_t *tile, game_t *game)
{
    entity_t *entity = game->wave->entity;
    float distance = 0;
    float time = 1 / (float)(tile->tower->att_spd);

    while (entity) {
        distance = my_get_distance(tile, entity->vec);
        if (distance <= tile->tower->range * 128 &&
            sfTime_asSeconds(sfClock_getElapsedTime(tile->tower->shoot)) >
                time) {
            sfClock_restart(tile->tower->shoot);
            entity->life -= tile->tower->dmg;
        }
        entity = entity->next;
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(tile->tower->shoot)) > time)
        sfClock_restart(tile->tower->shoot);
}

void my_tower_actions(game_t *game)
{
    tile_t *tile = game->tile;

    while (tile) {
        if (tile->is_tower == 1)
            my_tower_in_tile_attack(tile, game);
        tile = tile->next;
    }
    return;
}
