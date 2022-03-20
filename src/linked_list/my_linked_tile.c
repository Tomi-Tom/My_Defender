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

void my_free_tower(tower_t *tower)
{
    sfClock_destroy(tower->shoot);
    sfClock_destroy(tower->rotate);
    sfSprite_destroy(tower->body);
    sfSprite_destroy(tower->head);
    free(tower);
}

void my_free_tile_list(tile_t **list)
{
    tile_t *temp;

    while (*list != NULL) {
        temp = *list;
        *list = (*list)->next;
        if (temp->is_tower)
            my_free_tower(temp->tower);
        free(temp);
    }
    *list = NULL;
}