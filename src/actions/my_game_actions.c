/*
** EPITECH PROJECT, 2022
** MY_GAME_ACTIONS_C
** File description:
** my_game_actions
*/

#include "my_defender.h"

int is_tile_clicked(game_t *game, tile_t *tile)
{
    sfVector2i mouse = {0, 0};
    sfMouseButton click = 0;
    sfVector2i vec = {tile->x * 128, tile->y * 128};

    mouse = sfMouse_getPositionRenderWindow(game->window);
    if (mouse.x >= vec.x && mouse.x <= vec.x + 128 &&
        mouse.y >= vec.y && mouse.y <= vec.y + 128) {
            if (LEFT_CLICKED)
                return 1;
    }
    return 0;
}

int is_parse_tile_clicked(game_t *game)
{
    tile_t *tile = game->tile;

    while (tile) {
        if (is_tile_clicked(game, tile) && tile->is_tower == 0)
            my_tower_menu(game, tile);
        tile = tile->next;
    }
    return 0;
}

void my_game_actions(game_t *game)
{
    if (is_parse_tile_clicked(game)) {
        exit(0);
    }
    return;
}
