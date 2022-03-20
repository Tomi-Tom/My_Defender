/*
** EPITECH PROJECT, 2022
** MY_TOWER_MENU_C
** File description:
** my_tower_menu
*/

#include "my_defender.h"

void my_select_tower1(game_t *game, tile_t *tile)
{
    tile->tower = malloc(sizeof(tower_t));

    sfSprite *sp_head = sfSprite_create();
    sfTexture *tex_head = sfTexture_createFromFile("assets/tower/t1_h.png",
        NULL);
    sfSprite *sp_body = sfSprite_create();
    sfTexture *tex_body = sfTexture_createFromFile("assets/tower/t1_b.png",
        NULL);

    game->money->money -= 5;
    sfSprite_setTexture(sp_head, tex_head, sfTrue);
    sfSprite_setTexture(sp_body, tex_body, sfTrue);
    tile->tower->shoot = sfClock_create();
    tile->tower->rotate = sfClock_create();
    tile->is_tower = 1;
    tile->tower->dmg = 5;
    tile->tower->att_spd = 2;
    tile->tower->range = 2;
    tile->tower->head = sp_head;
    tile->tower->body = sp_body;
}

void my_select_tower2(game_t *game, tile_t *tile)
{
    tile->tower = malloc(sizeof(tower_t));

    sfSprite *sp_head = sfSprite_create();
    sfTexture *tex_head = sfTexture_createFromFile("assets/tower/t2_h.png",
        NULL);
    sfSprite *sp_body = sfSprite_create();
    sfTexture *tex_body = sfTexture_createFromFile("assets/tower/t2_b.png",
        NULL);

    game->money->money -= 10;
    sfSprite_setTexture(sp_head, tex_head, sfTrue);
    sfSprite_setTexture(sp_body, tex_body, sfTrue);
    tile->tower->shoot = sfClock_create();
    tile->tower->rotate = sfClock_create();
    tile->is_tower = 1;
    tile->tower->dmg = 10;
    tile->tower->att_spd = 4;
    tile->tower->range = 3;
    tile->tower->head = sp_head;
    tile->tower->body = sp_body;
}

void my_select_tower3(game_t *game, tile_t *tile)
{
    tile->tower = malloc(sizeof(tower_t));

    sfSprite *sp_head = sfSprite_create();
    sfTexture *tex_head = sfTexture_createFromFile("assets/tower/t3_h.png",
        NULL);
    sfSprite *sp_body = sfSprite_create();
    sfTexture *tex_body = sfTexture_createFromFile("assets/tower/t3_b.png",
        NULL);

    game->money->money -= 25;
    sfSprite_setTexture(sp_head, tex_head, sfTrue);
    sfSprite_setTexture(sp_body, tex_body, sfTrue);
    tile->tower->shoot = sfClock_create();
    tile->tower->rotate = sfClock_create();
    tile->is_tower = 1;
    tile->tower->dmg = 15;
    tile->tower->att_spd = 8;
    tile->tower->range = 4;
    tile->tower->head = sp_head;
    tile->tower->body = sp_body;
}

void my_select_tower4(game_t *game, tile_t *tile)
{
    tile->tower = malloc(sizeof(tower_t));

    sfSprite *sp_head = sfSprite_create();
    sfTexture *tex_head = sfTexture_createFromFile("assets/tower/t4_h.png",
        NULL);
    sfSprite *sp_body = sfSprite_create();
    sfTexture *tex_body = sfTexture_createFromFile("assets/tower/t4_b.png",
        NULL);

    game->money->money -= 50;
    sfSprite_setTexture(sp_head, tex_head, sfTrue);
    sfSprite_setTexture(sp_body, tex_body, sfTrue);
    tile->tower->shoot = sfClock_create();
    tile->tower->rotate = sfClock_create();
    tile->is_tower = 1;
    tile->tower->dmg = 20;
    tile->tower->att_spd = 16;
    tile->tower->range = 8;
    tile->tower->head = sp_head;
    tile->tower->body = sp_body;
}

void my_tower_menu(game_t *game, tile_t *tile)
{
    sfVector2i mouse = {0, 0};
    sfMouseButton click = 0;

    sfRenderWindow_drawSprite(game->window, game->wave->menu_tower, NULL);
    sfRenderWindow_display(game->window);
    while (game->wave->end_menu == 0) {
        mouse = sfMouse_getPositionRenderWindow(game->window);
        if (TOWER_SELECT)
            game->wave->end_menu = 1;
        if (TOWER1_SELECT)
            my_select_tower1(game, tile);
        if (TOWER2_SELECT)
            my_select_tower2(game, tile);
        if (TOWER3_SELECT)
            my_select_tower3(game, tile);
        if (TOWER4_SELECT)
            my_select_tower4(game, tile);
    }
    game->wave->end_menu = 0;
}