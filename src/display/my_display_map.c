/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_MAP_C
** File description:
** my_display_map
*/

#include "my_defender.h"

sfIntRect my_set_rect(game_t *game, char tile)
{
    sfIntRect rect;

    if (tile == '0')
        return rect;
    if (tile == 'D')
        tile = '1';
    rect.height = 128;
    rect.width = 128;
    rect.top = 0;
    rect.left = (tile - '1') * 128;
    return rect;
}

int is_last_tile(game_t *game, vec_t pos)
{
    int count = 0;
    if (pos.x == 0 || pos.y == 0 || game->map[pos.y + 1] == NULL ||
        game->map[pos.y][pos.x + 1] == '\0' ||
        game->map[pos.y][pos.x] != '1')
        return 0;
    if (game->map[pos.y + 1][pos.x] == '1' ||
        game->map[pos.y + 1][pos.x] == 'D')
        count++;
    if (game->map[pos.y - 1][pos.x] == '1' ||
        game->map[pos.y - 1][pos.x] == 'D')
        count++;
    if (game->map[pos.y][pos.x + 1] == '1' ||
        game->map[pos.y][pos.x + 1] == 'D')
        count++;
    if (game->map[pos.y][pos.x - 1] == '1' ||
        game->map[pos.y][pos.x - 1] == 'D')
        count++;
    if (count == 2)
        return 0;
    return 1;
}

void my_display_tile(game_t *game, char tile, vec_t pos)
{
    sfIntRect rect = my_set_rect(game, tile);
    sfVector2f vec;

    vec.x = pos.x * 128;
    vec.y = pos.y * 128;
    sfSprite_setTextureRect(game->bgsprite, rect);
    sfSprite_setPosition(game->bgsprite, vec);
    sfRenderWindow_drawSprite(game->window, game->bgsprite, NULL);
    if (tile == 'D') {
        sfSprite_setPosition(game->portal, vec);
        sfRenderWindow_drawSprite(game->window, game->portal, NULL);
    }
    if (is_last_tile(game, pos)) {
        sfSprite_setPosition(game->base, vec);
        sfRenderWindow_drawSprite(game->window, game->base, NULL);
    }
}

void my_display_map(game_t *game)
{
    int i = 0;
    int j = 0;
    vec_t pos;

    while (game->map[i]) {
        j = 0;
        while (game->map[i][j]) {
            pos.x = j;
            pos.y = i;
            my_display_tile(game, game->map[i][j], pos);
            j++;
        }
        i++;
    }
    return;
}
