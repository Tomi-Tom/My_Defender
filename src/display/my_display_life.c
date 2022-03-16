/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_LIFE_C
** File description:
** my_display_life
*/

#include "my_defender.h"

void my_display_life(game_t *game)
{
    sfVector2f vec;
    float coef = (game->life->life / game->life->life_max) * 100;

    vec.x = 710;
    vec.y = 15;
    game->life->rect_hp.width = (game->life->width * coef) / 100;
    sfSprite_setPosition(game->life->base_hp, vec);
    vec.x = 710 + 112;
    vec.y = 15 + 34;
    sfSprite_setPosition(game->life->hp, vec);
    sfSprite_setTextureRect(game->life->hp, game->life->rect_hp);
    sfSprite_setTextureRect(game->life->base_hp, game->life->rect_base);
    sfRenderWindow_drawSprite(game->window, game->life->hp, NULL);
    sfRenderWindow_drawSprite(game->window, game->life->base_hp, NULL);
}
