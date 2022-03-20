/*
** EPITECH PROJECT, 2022
** MY_INIT_TOWER_C
** File description:
** my_init_tower
*/

#include "my_defender.h"

void my_parse_tiles(game_t *game)
{
    int i = 0;
    int j = 0;

    while (game->map[i]) {
        j = 0;
        while (game->map[i][j]) {
            game->map[i][j] == '2' ? game->tile = my_append_tile(game, j, i)
                : NULL;
            j++;
        }
        i++;
    }
}

void my_init_tile(game_t *game)
{
    game->tile = NULL;

    my_parse_tiles(game);
    return;
}
