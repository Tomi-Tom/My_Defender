/*
** EPITECH PROJECT, 2022
** MY_INIT_PAUSE_C
** File description:
** my_init_pause
*/

#include "my_defender.h"

void my_init_pause_sprite(game_t *game)
{
    sfTexture *t_bg =
        sfTexture_createFromFile("assets/menu_pause/menu_pause.png", NULL);
    sfTexture *t_r =
        sfTexture_createFromFile("assets/menu_pause/play_sheet.png", NULL);
    sfTexture *t_m =
        sfTexture_createFromFile("assets/menu_pause/menu_sheet.png", NULL);
    sfTexture *t_l =
        sfTexture_createFromFile("assets/menu_pause/leave_sheet.png", NULL);
    sfSprite *sp_bg = sfSprite_create();
    sfSprite *sp_r = sfSprite_create();
    sfSprite *sp_m = sfSprite_create();
    sfSprite *sp_l = sfSprite_create();
    sfSprite_setTexture(sp_bg, t_bg, sfTrue);
    sfSprite_setTexture(sp_r, t_r, sfTrue);
    sfSprite_setTexture(sp_m, t_m, sfTrue);
    sfSprite_setTexture(sp_l, t_l, sfTrue);
    game->pause_menu->bg = sp_bg;
    game->pause_menu->resume->sprite = sp_r;
    game->pause_menu->menu->sprite = sp_m;
    game->pause_menu->leave->sprite = sp_l;
}

void my_init_pause_rect(game_t *game)
{
    sfIntRect resume = {0, 0, 535, 120};
    sfIntRect menu = {0, 0, 535, 120};
    sfIntRect leave = {0, 0, 535, 120};

    game->pause_menu->resume->rect = resume;
    game->pause_menu->menu->rect = menu;
    game->pause_menu->leave->rect = leave;
}

void my_init_pause_vec(game_t *game)
{
    vec_t resume = {960 - 535/2, 250};
    vec_t menu = {960 - 535/2, 450};
    vec_t leave = {960 - 535/2, 650};

    game->pause_menu->resume->vec = resume;
    game->pause_menu->menu->vec = menu;
    game->pause_menu->leave->vec = leave;
}

void my_init_pause(game_t *game)
{
    game->pause_menu = malloc(sizeof(pause_t));

    game->pause_menu->resume = malloc(sizeof(button_t));
    game->pause_menu->menu = malloc(sizeof(button_t));
    game->pause_menu->leave = malloc(sizeof(button_t));
    my_init_pause_sprite(game);
    my_init_pause_rect(game);
    my_init_pause_vec(game);
}
