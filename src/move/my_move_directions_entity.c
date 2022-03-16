/*
** EPITECH PROJECT, 2022
** MY_MOVE_DIRECTIONS_ENTITY_C
** File description:
** my_move_directions_entity
*/

#include "my_defender.h"

void my_move_up(wave_t *wave, entity_t *entity)
{
    sfVector2f vec;

    vec.x = entity->vec.x * 128 + 32;
    vec.y = entity->vec.y * 128 + 32 - entity->moving;
    sfSprite_setPosition(entity->sprite, vec);
}

void my_move_down(wave_t *wave, entity_t *entity)
{
    sfVector2f vec;

    vec.x = entity->vec.x * 128 + 32;
    vec.y = entity->vec.y * 128 + 32 + entity->moving;
    sfSprite_setPosition(entity->sprite, vec);
}

void my_move_left(wave_t *wave, entity_t *entity)
{
    sfVector2f vec;

    vec.x = entity->vec.x * 128 + 32 - entity->moving;
    vec.y = entity->vec.y * 128 + 32;
    sfSprite_setPosition(entity->sprite, vec);
}

void my_move_right(wave_t *wave, entity_t *entity)
{
    sfVector2f vec;

    vec.x = entity->vec.x * 128 + 32 + entity->moving;
    vec.y = entity->vec.y * 128 + 32;
    sfSprite_setPosition(entity->sprite, vec);
}
