/*
** EPITECH PROJECT, 2022
** MY_PROJECT_H
** File description:
** MY_PROJECT_H
*/

#ifndef MY_PROJECT_H
    #define MY_PROJECT_H

    #include "my.h"
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <assert.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/mman.h>

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

typedef struct vec_s {
    int x;
    int y;
} vec_t;


    #include "my_tower.h"
    #include "my_tile.h"
    #include "my_entity.h"
    #include "my_wave.h"
    #include "my_button.h"
    #include "my_life.h"
    #include "my_music.h"
    #include "my_sound.h"
    #include "my_menu.h"
    #include "my_money.h"
    #include "my_pause.h"
    #include "my_settings.h"

typedef struct game_s {
    int end;
    int end_game;
    int pause;
    sfFont *font;
    sfRenderWindow *window;
    sfSprite *bgsprite;
    sfSprite *portal;
    sfSprite *base;
    sfText *best_wave;
    char **map;
    menu_t *menu;
    sound_t *sound;
    pause_t *pause_menu;
    music_t *music;
    life_t *life;
    money_t *money;
    tile_t *tile;
    wave_t *wave;
    sfEvent event;
} game_t;

/*==========================[BEGIN]==========================*/

int my_error_handling(int ac, char **av);
int my_help(void);

/*==========================[WINDOW]=========================*/

void my_window(int ac, char **av);

/*==========================[INIT]==========================*/

char *my_parse_path(char **map);
game_t *my_init_game(char *filename);
void my_init_ennemies(game_t *game);
void my_init_life_and_money(game_t *game);
void my_init_music(game_t *game);
void my_init_menu(game_t *game);
void my_init_pause(game_t *game);
void my_init_tile(game_t *game);

/*==========================[LOOP]==========================*/

void my_game_loop(game_t *game);
void my_menu_loop(game_t *game);
void my_pause_menu(game_t *game);
void my_tower_menu(game_t *game, tile_t *tile);

/*=========================[CREATE]=========================*/

void my_create_ennemies(game_t *game);

/*=========================[ACTIONS]========================*/

void my_game_actions(game_t *game);
void my_tower_actions(game_t *game);

/*==========================[MOVE]==========================*/

void my_move_ennemie(entity_t *entity, wave_t *wave, game_t *game);
void my_move_up(wave_t *wave, entity_t *entity);
void my_move_down(wave_t *wave, entity_t *entity);
void my_move_left(wave_t *wave, entity_t *entity);
void my_move_right(wave_t *wave, entity_t *entity);

/*=========================[DISPLAY]========================*/

void my_display_menu(game_t *game);
void my_display_map(game_t *game);
void my_display_tower(game_t *game);
void my_display_ennemies(game_t *game);
void my_display_life(game_t *game);
void my_display_money(game_t *game);

void my_display_button(button_t *button, game_t *game);

/*=========================[PARSING]========================*/

vec_t get_departure(char **map);

/*==========================[EVENT]=========================*/

int my_poll_event(game_t *game);
int is_button_pressed(button_t *button, sfVector2i mouse, sfMouseButton click);

/*=========================[LINKED]=========================*/

entity_t *my_append_entity(game_t *game);
entity_t *my_delete_entity(game_t *game, int id);

tile_t *my_append_tile(game_t *game, int x, int y);

/*==========================[FREE]==========================*/

void my_free_game(game_t *game);
void my_free_entity_list(entity_t **list);
void my_free_entity(entity_t *entity);
void my_free_button(button_t *button);
void my_free_tile_list(tile_t **list);
void my_free_tower(tower_t *tower);

#endif /* !MY_PROJECT_H */
