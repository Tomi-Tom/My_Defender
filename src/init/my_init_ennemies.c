/*
** EPITECH PROJECT, 2022
** MY_INIT_ENNEMIES_C
** File description:
** my_init_ennemies
*/

#include "my_defender.h"

void my_init_ennemies2(game_t *game)
{
    game->wave->count = 0;
    game->wave->wave = 0;
    game->wave->actual_wave = 0;
    game->wave->wave_max = 5;
    game->wave->end_menu = 0;
    game->wave->spd = 1;
}

void my_init_ennemies(game_t *game)
{
    sfTexture *tex_e =
        sfTexture_createFromFile("assets/entity/ennemi_sheet.png", NULL);
    sfSprite *sp_e = sfSprite_create();
    sfTexture *tex_t = sfTexture_createFromFile("assets/game/menu_towers.png",
        NULL);
    sfSprite *sp_t = sfSprite_create();

    sfSprite_setTexture(sp_e, tex_e, sfTrue);
    sfSprite_setTexture(sp_t, tex_t, sfTrue);
    game->wave->time = sfClock_create();
    game->wave->begin = get_departure(game->map);
    game->wave->entity = NULL;
    my_init_ennemies2(game);
    game->wave->sprite = sp_e;
    game->wave->menu_tower = sp_t;
    return;
}