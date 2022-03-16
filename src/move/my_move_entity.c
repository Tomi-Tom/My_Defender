/*
** EPITECH PROJECT, 2022
** MY_MOVE_ENTITY_C
** File description:
** my_move_entity
*/

#include "my_defender.h"

void my_set_new_pos(wave_t *wave, entity_t *entity)
{
    if (wave->path[entity->tile] == 'U')
        entity->vec.y -= 1;
    if (wave->path[entity->tile] == 'D')
        entity->vec.y += 1;
    if (wave->path[entity->tile] == 'L')
        entity->vec.x -= 1;
    if (wave->path[entity->tile] == 'R')
        entity->vec.x += 1;
}

void my_move_ennemie(entity_t *entity, wave_t *wave, game_t *game)
{
    if (entity->moving == 128) {
        entity->moving = 0;
        my_set_new_pos(wave, entity);
        entity->tile += 1;
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(entity->move)) > 0.008) {
        entity->moving += entity->spd;
        sfClock_restart(entity->move);
    }
    if (wave->path[entity->tile] == 'U')
        my_move_up(wave, entity);
    if (wave->path[entity->tile] == 'D')
        my_move_down(wave, entity);
    if (wave->path[entity->tile] == 'L')
        my_move_left(wave, entity);
    if (wave->path[entity->tile] == 'R')
        my_move_right(wave, entity);
}
