/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_ENNEMIES_C
** File description:
** my_display_ennemies
*/

#include "my_defender.h"

void my_anim_ennemie(entity_t *entity, wave_t *wave, game_t *game)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(entity->anim)) > 0.05) {
        entity->rect.left += 64;
        sfClock_restart(entity->anim);
    }
    if (entity->rect.left == 64 * 6)
        entity->rect.left = 0;
    return;
}

void my_move_ennemies(game_t *game)
{
    entity_t *tmp = game->wave->entity;
    int count = 0;

    while (tmp) {
        if (game->wave->path[tmp->tile] == '\0' || game->wave->entity->life == 0) {
            game->wave->entity = my_delete_entity(game, count);
            game->life->life -= 1;
        }
        count++;
        my_move_ennemie(tmp, game->wave, game);
        my_anim_ennemie(tmp, game->wave, game);
        sfSprite_setTextureRect(tmp->sprite, tmp->rect);
        sfRenderWindow_drawSprite(game->window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}

void my_display_ennemies(game_t *game)
{
    my_create_ennemies(game);
    my_move_ennemies(game);
    return;
}