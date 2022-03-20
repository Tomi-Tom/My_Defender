/*
** EPITECH PROJECT, 2022
** MY_INIT_GAME_C
** File description:
** my_init_game
*/

#include "my_defender.h"

void my_set_wave_info(game_t *game)
{
    char *path =  my_parse_path(game->map);

    game->wave = malloc(sizeof(wave_t));
    game->wave->path = path;
}

void my_set_game_map(game_t *game, char *filename)
{
    char *buf = my_read_file(filename);
    game->map = my_split(buf, "\n");
}

void my_set_game_base_info(game_t *game)
{
    sfVideoMode mode = {1920, 1024, 30};
    sfRenderWindow *window = sfRenderWindow_create(mode,
        "MY_COOL_DEFENDER", sfResize | sfClose, NULL);
    sfTexture *texture = sfTexture_createFromFile("assets/tileset/map2.png",
        NULL);
    sfSprite *sprite = sfSprite_create();
    sfTexture *tex_portal =
        sfTexture_createFromFile("assets/tileset/portal.png", NULL);
    sfSprite *sp_portal = sfSprite_create();
    sfTexture *tex_base =
        sfTexture_createFromFile("assets/tileset/base.png", NULL);
    sfSprite *sp_base = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(sp_portal, tex_portal, sfTrue);
    sfSprite_setTexture(sp_base, tex_base, sfTrue);
    game->window = window;
    game->bgsprite = sprite;
    game->portal = sp_portal;
    game->base = sp_base;
}

void my_init_sound(game_t *game)
{
    game->sound = malloc(sizeof(sound_t));

    game->sound->click = sfMusic_createFromFile("assets/sound/click.wav");
    game->sound->click_htp =
        sfMusic_createFromFile("assets/sound/click_htp.wav");
}

game_t *my_init_game(char *filename)
{
    game_t *game = malloc(sizeof(game_t) * 2);

    my_set_game_map(game, filename);
    my_set_game_base_info(game);
    my_set_wave_info(game);
    game->end = 0;
    game->end_game = 0;
    my_init_menu(game);
    my_init_ennemies(game);
    my_init_life_and_money(game);
    my_init_music(game);
    my_init_pause(game);
    my_init_tile(game);
    my_init_sound(game);
    return game;
}
