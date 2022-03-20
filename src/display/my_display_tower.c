/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_TOWER_C
** File description:
** my_display_tower
*/

#include "my_defender.h"

void my_display_tower(game_t *game)
{
    tile_t *tile = game->tile;
    sfVector2f vec = {0, 0};


    while (tile) {
        if (tile->is_tower == 1) {
            vec.x = tile->x * 128;
            vec.y = tile->y * 128;
            sfSprite_setPosition(tile->tower->body, vec);
            sfSprite_setPosition(tile->tower->head, vec);
            sfRenderWindow_drawSprite(game->window, tile->tower->body, NULL);
            sfRenderWindow_drawSprite(game->window, tile->tower->head, NULL);
        }
        tile = tile->next;
    }
    return;
}