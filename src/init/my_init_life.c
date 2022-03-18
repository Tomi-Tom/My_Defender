/*
** EPITECH PROJECT, 2022
** MY_INIT_LIFE_C
** File description:
** my_init_life
*/

#include "my_defender.h"

void my_init_rect_life(game_t *game)
{
    game->life->rect_base.top = 0;
    game->life->rect_base.left = 0;
    game->life->rect_base.height = 100;
    game->life->rect_base.width = 500;
    game->life->rect_hp.top = 0;
    game->life->rect_hp.left = 0;
    game->life->rect_hp.height = 33;
    game->life->rect_hp.width = 371;
}

void my_init_life(game_t *game)
{
    sfTexture *tex_base = sfTexture_createFromFile("assets/base_hp.png",
        NULL);
    sfSprite *sp_base = sfSprite_create();
    sfTexture *tex_hp = sfTexture_createFromFile("assets/hp.png",
        NULL);
    sfSprite *sp_hp = sfSprite_create();

    sfSprite_setTexture(sp_base, tex_base, sfTrue);
    sfSprite_setTexture(sp_hp, tex_hp, sfTrue);
    game->life = malloc(sizeof(life_t));

    game->life->base_hp = sp_base;
    game->life->hp = sp_hp;
    game->life->life_max = 100;
    game->life->life = game->life->life_max;
    game->life->width = 371;
    my_init_rect_life(game);
}
