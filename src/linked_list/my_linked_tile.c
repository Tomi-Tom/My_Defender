/*
** EPITECH PROJECT, 2022
** MY_LINKED_ENTITY_C
** File description:
** my_linked_entity
*/

#include "my_defender.h"

tile_t *my_init_tile_elem(game_t *game, int x, int y)
{
    tile_t *elem = malloc(sizeof(tile_t));

    elem->x = x;
    elem->y = y;
    elem->is_tower = 0;
    elem->tower = NULL;
    elem->next = NULL;
    return elem;
}

tile_t *my_append_tile(game_t *game, int x, int y)
{
    tile_t *add = my_init_tile_elem(game, x, y);
    tile_t *tmp = game->tile;
    static int i = 0;

    i++;
    if (game->tile == NULL) {
        return add;
    }
    while (game->tile->next != NULL)
        game->tile = game->tile->next;
    game->tile->next = add;
    return tmp;
}
