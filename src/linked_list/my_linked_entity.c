/*
** EPITECH PROJECT, 2022
** MY_LINKED_ENTITY_C
** File description:
** my_linked_entity
*/

#include "my_defender.h"

entity_t *my_init_entity(game_t *game)
{
    entity_t *elem = malloc(sizeof(entity_t));

    elem->anim = sfClock_create();
    elem->move = sfClock_create();
    elem->rect.left = 0;
    elem->rect.top = 0;
    elem->rect.height = ENTITY_HEIGHT;
    elem->rect.width = ENTITY_WIDTH;
    elem->sprite = game->wave->sprite;
    elem->type = 1;
    elem->vec = game->wave->begin;
    elem->tile = 0;
    elem->moving = 0;
    elem->spd = ENTITY_SPEED;
    elem->life = ENTITY_LIFE;
    elem->prev = NULL;
    elem->next = NULL;
    return elem;
}

entity_t *my_append_entity(game_t *game)
{
    entity_t *add = my_init_entity(game);
    entity_t *tmp = game->wave->entity;

    if (game->wave->entity == NULL) {
        return add;
    }
    while (game->wave->entity->next != NULL)
        game->wave->entity = game->wave->entity->next;
    add->prev = game->wave->entity;
    game->wave->entity->next = add;
    return tmp;
}

entity_t *my_delete_entity(game_t *game, int id)
{
    int count = 0;
    entity_t *tmp_next = NULL;
    entity_t *tmp_prev = NULL;
    entity_t *to_free = NULL;
    entity_t *tmp = game->wave->entity;

    while (count < id) {
        game->wave->entity = game->wave->entity->next;
        count++;
    }
    to_free = game->wave->entity;
    tmp_next = game->wave->entity->next;
    tmp_prev = game->wave->entity->prev;
    if (tmp_next == NULL && tmp_prev == NULL)
        return NULL;
    if (tmp_prev)
        tmp_prev->next = tmp_next;
    if (tmp_next)
        tmp_next->prev = tmp_prev;
    return tmp;
}
