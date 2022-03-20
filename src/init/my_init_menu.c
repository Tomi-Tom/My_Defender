/*
** EPITECH PROJECT, 2022
** MY_INIT_MENU_C
** File description:
** my_init_menu
*/

#include "my_defender.h"

void my_init_menu_sprites(game_t *game)
{
    sfSprite *sp_back = sfSprite_create();
    sfTexture *tex_back = sfTexture_createFromFile("assets/menu/menu_back.png",
        NULL);
    sfSprite *sp_map = sfSprite_create();
    sfTexture *tex_map = sfTexture_createFromFile("assets/menu/menu_map.png",
        NULL);
    sfSprite *sp_front = sfSprite_create();
    sfTexture *tex_front =
        sfTexture_createFromFile("assets/menu/menu_front.png", NULL);

    sfSprite_setTexture(sp_back, tex_back, sfTrue);
    sfSprite_setTexture(sp_map, tex_map, sfTrue);
    sfSprite_setTexture(sp_front, tex_front, sfTrue);
    game->menu = malloc(sizeof(menu_t));
    game->menu->back = sp_back;
    game->menu->map = sp_map;
    game->menu->front = sp_front;
}

void my_set_menu_vectors(menu_t *menu)
{
    vec_t play;
    vec_t hplay;
    vec_t leave;

    play.x = 1369;
    play.y = 320;
    hplay.x = 1369;
    hplay.y = 320 + 180;
    leave.x = 1369;
    leave.y = 320 + 180 + 180;
    menu->play->vec = play;
    menu->how_to_play->vec = hplay;
    menu->leave->vec = leave;
}

void my_set_menu_rect(menu_t *menu)
{
    sfIntRect play;
    sfIntRect hplay;
    sfIntRect leave;

    play.top = 0;
    play.left = 0;
    play.height = 120;
    play.width = 535;
    hplay.top = 0;
    hplay.left = 0;
    hplay.height = 120;
    hplay.width = 535;
    leave.top = 0;
    leave.left = 0;
    leave.height = 120;
    leave.width = 535;
    menu->play->rect = play;
    menu->how_to_play->rect = hplay;
    menu->leave->rect = leave;
}

void my_set_buttons(menu_t *menu)
{
    sfSprite *sp_play = sfSprite_create();
    sfTexture *tex_play =
        sfTexture_createFromFile("assets/menu/play_sheet.png", NULL);
    sfSprite *sp_hplay = sfSprite_create();
    sfTexture *tex_hplay =
        sfTexture_createFromFile("assets/menu/how_to_play_sheet.png", NULL);
    sfSprite *sp_leave = sfSprite_create();
    sfTexture *tex_leave =
        sfTexture_createFromFile("assets/menu/leave_sheet.png", NULL);
    sfSprite_setTexture(sp_play, tex_play, sfTrue);
    sfSprite_setTexture(sp_hplay, tex_hplay, sfTrue);
    sfSprite_setTexture(sp_leave, tex_leave, sfTrue);
    menu->play->sprite = sp_play;
    menu->how_to_play->sprite = sp_hplay;
    menu->leave->sprite = sp_leave;
    my_set_menu_vectors(menu);
    my_set_menu_rect(menu);
}

void my_init_menu(game_t *game)
{
    game->font = sfFont_createFromFile("assets/font/Hartone Softed.ttf");
    sfVector2f vec = {520, 450};

    game->menu = malloc(sizeof(menu_t));
    my_init_menu_sprites(game);
    game->menu->scale = 1;
    game->menu->best_wave = 0;
    game->best_wave = sfText_create();
    sfText_setFont(game->best_wave, game->font);
    sfText_setCharacterSize(game->best_wave, 300);
    sfText_setPosition(game->best_wave, vec);
    sfText_setString(game->best_wave, "0");
    game->menu->play = malloc(sizeof(button_t));
    game->menu->how_to_play = malloc(sizeof(button_t));
    game->menu->leave = malloc(sizeof(button_t));
    my_set_buttons(game->menu);
    return;
}
