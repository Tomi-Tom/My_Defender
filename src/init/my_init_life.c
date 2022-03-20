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

void my_init_life_text(game_t *game)
{
    sfVector2f vec = {732, 50};

    game->life->t_life = sfText_create();
    sfText_setFont(game->life->t_life, game->font);
    sfText_setCharacterSize(game->life->t_life, 25);
    sfText_setPosition(game->life->t_life, vec);
    sfText_setString(game->life->t_life, "100/100");
    return;
}

void my_init_money(game_t *game)
{
    sfVector2f vec = {32, 0};
    sfTexture *tex_money =
        sfTexture_createFromFile("assets/game/money_sheet.png", NULL);
    sfSprite *sp_money = sfSprite_create();

    sfSprite_setTexture(sp_money, tex_money, sfTrue);
    game->money = malloc(sizeof(money_t));
    game->money->t_money = sfText_create();
    sfText_setFont(game->money->t_money, game->font);
    sfText_setCharacterSize(game->money->t_money, 30);
    sfText_setPosition(game->money->t_money, vec);
    sfText_setString(game->money->t_money, "50$");
    game->money->rect.top = 0;
    game->money->rect.left = 0;
    game->money->rect.height == 32;
    game->money->rect.width = 32;
    game->money->time = sfClock_create();
    game->money->money = 50;
    game->money->sp_money = sp_money;
}

void my_init_life_and_money(game_t *game)
{
    sfTexture *tex_base = sfTexture_createFromFile("assets/life/base_hp.png",
        NULL);
    sfSprite *sp_base = sfSprite_create();
    sfTexture *tex_hp = sfTexture_createFromFile("assets/life/hp.png",
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
    my_init_life_text(game);
    my_init_rect_life(game);
    my_init_money(game);
}
