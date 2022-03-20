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

    if (elem == NULL)
        return NULL;
    elem->anim = sfClock_create();
    elem->move = sfClock_create();
    elem->rect = (sfIntRect) {.left = 0, .top = 0, .height = 64, .width = 64};
    elem->sprite = game->wave->sprite;
    elem->type = 1;
    elem->vec = game->wave->begin;
    elem->tile = 0;
    elem->moving = 0;
    elem->spd = game->wave->spd;
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
    entity_t *head = game->wave->entity;
    entity_t *previous = head;
    entity_t *deleted = NULL;

    for (size_t i = 0; i < id && previous != NULL; ++i)
        previous = previous->next;
    if (previous != NULL) {
        deleted = previous->next;
        if (previous->next != NULL)
            previous->next = previous->next->next;
        else
            previous->next = NULL;
    }
    game->wave->entity = head;
    return deleted;
}

void my_free_entity(entity_t *entity)
{
    sfClock_destroy(entity->anim);
    sfClock_destroy(entity->move);
    free(entity);
}

void my_free_entity_list(entity_t **list)
{
    entity_t *temp;

    while (*list != NULL) {
        temp = *list;
        *list = (*list)->next;
        my_free_entity(temp);
    }
    *list = NULL;
}